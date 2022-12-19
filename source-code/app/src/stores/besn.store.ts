import { ref } from 'vue'
import { defineStore } from 'pinia'
import { besAirService } from '@/services/bes-air.service'
import axios from 'axios'

export type BesnState = 'offline' | 'on' | 'off'

export const useBesnStore = defineStore('besn', () => {
  const besnState = ref<BesnState>('offline')
  const pending = ref(false)

  axios.interceptors.request.use(
    function (config) {
      if (pending.value) return Promise.reject(new Error('Pending request'))
      pending.value = true
      return config
    },
    function (error) {
      pending.value = false
      return Promise.reject(error)
    }
  )
  axios.interceptors.response.use(
    function (response) {
      pending.value = false
      return response
    },
    function (error) {
      pending.value = false
      return Promise.reject(error)
    }
  )

  async function connect() {
    catchError(async () => {
      const response = await besAirService.getBesnState()
      if (response.data.state === 'on' || response.data.state === 'off') {
        besnState.value = response.data.state
      } else {
        besnState.value = 'offline'
      }
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

  connect()

  return { besnState, pending, connect, toggleBesn }
})
