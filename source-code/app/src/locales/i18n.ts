import { createI18n } from 'vue-i18n'

import en from '@/locales/en.json'
import de from '@/locales/de.json'

export const defaultLocale = 'en'
export type LocaleOption = 'en' | 'de'
export const localeOptions: LocaleOption[] = [defaultLocale, 'de']

export const i18n = createI18n({
  locale: defaultLocale,
  fallbackLocale: 'en',
  messages: {
    en,
    de,
  },
})
