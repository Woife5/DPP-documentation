import { ref } from 'vue'
import { defineStore } from 'pinia'
import { i18n, type LocaleOption } from '@/locales/i18n'

export const useLocaleStore = defineStore('locale', () => {
  const selectedLocale = ref<LocaleOption>('en')

  function setLocale(locale: LocaleOption) {
    selectedLocale.value = locale
    i18n.global.locale = selectedLocale.value
  }

  return { selectedLocale, setLocale }
})
