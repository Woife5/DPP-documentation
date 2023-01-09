import { ref, watch } from 'vue'
import { defineStore } from 'pinia'
import type { LocaleOption } from '@/locales/i18n'
import { useStorage } from '@vueuse/core'
import { useI18n } from 'vue-i18n'

export type BesnLocale = ''

export const useLocaleStore = defineStore('locale', () => {
  const { locale } = useI18n()
  const selectedLocale = ref(useStorage<LocaleOption>('locale', 'en-GB'))

  function init() {
    locale.value = selectedLocale.value
  }

  watch(selectedLocale, () => {
    locale.value = selectedLocale.value
  })

  return { selectedLocale, init }
})
