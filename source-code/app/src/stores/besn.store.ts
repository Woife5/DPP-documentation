import { ref } from 'vue'
import { defineStore } from 'pinia'
import { besAirService } from '@/services/bes-air.service'

export type BesnState = 'offline' | 'on' | 'off'

export const useBesnStore = defineStore('besn', () => {
  const besnState = ref<BesnState>('offline')

  besAirService
    .getBesnState()
    .then((response) => (besnState.value = response.state))

  async function activateBesn() {
    try {
      await besAirService.startBesn()
      besnState.value = 'on'
    } catch {
      besnState.value = 'offline'
    }
  }

  async function deactivateBesn() {
    try {
      await besAirService.stopBesn()
      besnState.value = 'off'
    } catch {
      besnState.value = 'offline'
    }
  }

  async function toggleBesn() {
    if (besnState.value === 'on') {
      await deactivateBesn()
    } else {
      await activateBesn()
    }
  }

  return { besnState, activateBesn, deactivateBesn, toggleBesn }
})
