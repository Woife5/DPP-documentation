import { ref } from 'vue'
import { defineStore } from 'pinia'
import { besAirService } from '@/services/bes-air.service'

export type BesnState = 'offline' | 'on' | 'off'

export const useBesnStore = defineStore('besn', () => {
  const besnState = ref<BesnState>('offline')

  async function connect() {
    catchError(async () => {
      const response = await besAirService.getBesnState()
      besnState.value = response.state
    })
  }

  async function catchError(f: () => Promise<void>) {
    try {
      await f()
    } catch {
      besnState.value = 'offline'
    }
  }

  async function activateBesn() {
    catchError(async () => {
      await besAirService.startBesn()
      besnState.value = 'on'
    })
  }

  async function deactivateBesn() {
    catchError(async () => {
      await besAirService.stopBesn()
      besnState.value = 'off'
    })
  }

  async function toggleBesn() {
    if (besnState.value === 'on') {
      await deactivateBesn()
    } else {
      await activateBesn()
    }
  }

  return { besnState, connect, activateBesn, deactivateBesn, toggleBesn }
})
