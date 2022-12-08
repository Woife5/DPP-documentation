import { ref } from 'vue'
import { defineStore } from 'pinia'

export const useConnectionStore = defineStore('connection', () => {
  const connectionUrl = ref<string>()
  const connectionUrlKey = 'connection-url'

  function initFromLocalStorage() {
    const url = localStorage.getItem('connection-url')
    if (url != null) {
      connectionUrl.value = url
    }
  }

  function updateLocalStorage() {
    if (connectionUrl.value == null) return
    localStorage.setItem(connectionUrlKey, connectionUrl.value)
    console.log('connectionUrl', connectionUrl.value)
  }

  function setConnectionUrl(url: string) {
    connectionUrl.value = url
    console.log('setConnectionUrl')
    updateLocalStorage()
  }

  return { connectionUrl, setConnectionUrl, initFromLocalStorage }
})
