import { ref } from 'vue'
import { defineStore } from 'pinia'
import {
  i18n,
  isLocaleOption,
  localeOptions,
  type LocaleOption,
} from '@/locales/i18n'

export const useLocaleStore = defineStore('locale', () => {
  const selectedLocale = ref<LocaleOption>('en')

  function setI18nLocale(locale: LocaleOption) {
    selectedLocale.value = locale
    i18n.global.locale = selectedLocale.value
  }

  function initFromLocalStorage() {
    const locale = localStorage.getItem('locale')
    if (locale != null && isLocaleOption(locale)) {
      setI18nLocale(locale)
    } else {
      updateLocalStorage()
    }
  }

  function updateLocalStorage() {
    localStorage.setItem('locale', selectedLocale.value)
  }

  function setLocale(locale: LocaleOption) {
    setI18nLocale(locale)
    updateLocalStorage()
  }

  initFromLocalStorage()

  return { selectedLocale, setLocale }
})
