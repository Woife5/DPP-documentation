import { ref } from 'vue'
import { defineStore } from 'pinia'
import { i18n, isLocaleOption, type LocaleOption } from '@/locales/i18n'

export const useLocaleStore = defineStore('locale', () => {
  const selectedLocale = ref<LocaleOption>('en-GB')

  function setI18nLocale(locale: LocaleOption) {
    selectedLocale.value = locale
    i18n.global.locale = selectedLocale.value
  }

  function initFromLocalStorage() {
    const locale = localStorage.getItem('locale')
    console.log('locale', locale)
    if (locale != null && isLocaleOption(locale)) {
      setI18nLocale(locale)
      console.log('setI18nLocale(locale)', locale)
    } else {
      updateLocalStorage()
      console.log('updateLocalStorage()', locale)
    }
  }

  function updateLocalStorage() {
    localStorage.setItem('locale', selectedLocale.value)
  }

  function setLocale(locale: LocaleOption) {
    setI18nLocale(locale)
    updateLocalStorage()
  }

  return { selectedLocale, setLocale, initFromLocalStorage }
})
