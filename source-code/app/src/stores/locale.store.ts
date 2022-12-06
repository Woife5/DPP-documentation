import { ref } from 'vue'
import { defineStore } from 'pinia'
import {
  defaultLocale,
  i18n,
  type LocaleOption,
  localeOptions,
} from '@/locales/i18n'

export const useLocaleStore = defineStore('locale', () => {
  const selectedLocale = ref<LocaleOption>('en')

  // function toggleLocale() {
  //   // Only works with 2 locales
  //   setLocale(
  //     localeOptions.find((option) => option != selectedLocale.value) ??
  //       defaultLocale
  //   )
  // }

  function setLocale(locale: LocaleOption) {
    selectedLocale.value = locale
    i18n.global.locale = selectedLocale.value
  }

  return { selectedLocale, setLocale }
})
