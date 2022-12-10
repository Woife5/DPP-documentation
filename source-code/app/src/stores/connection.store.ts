import { ref } from 'vue'
import { defineStore } from 'pinia'
import { useStorage } from '@vueuse/core'

export const useConnectionStore = defineStore('connection', () => {
  const connectionUrl = ref(useStorage('connection-url', ''))

  return { connectionUrl }
})
