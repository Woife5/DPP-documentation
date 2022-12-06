import { createI18n } from 'vue-i18n'

import en from '@/locales/en.json'
import de from '@/locales/de.json'
import at from '@/locales/at.json'

export const defaultLocale = 'en'
export const localeOptions = [defaultLocale, 'de', 'at'] as const
export type LocaleOption = typeof localeOptions[number]

export const i18n = createI18n({
  locale: defaultLocale,
  fallbackLocale: 'en',
  messages: {
    en,
    de,
    at,
  },
})
