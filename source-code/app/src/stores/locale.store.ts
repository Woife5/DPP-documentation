import { ref, watch } from 'vue'
import { defineStore } from 'pinia'
import { i18n, type LocaleOption } from '@/locales/i18n'
import { useStorage } from '@vueuse/core'

export const useLocaleStore = defineStore('locale', () => {
  const selectedLocale = ref(useStorage<LocaleOption>('locale', 'en-GB'))

  function init() {
    i18n.global.locale = selectedLocale.value
  }

  watch(selectedLocale, () => {
    i18n.global.locale = selectedLocale.value
  })

  return { selectedLocale, init }
})
