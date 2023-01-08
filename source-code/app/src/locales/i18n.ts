import { createI18n } from 'vue-i18n'

import enGB from '@/locales/en-GB.json'
import deDE from '@/locales/de-DE.json'
import deAT from '@/locales/de-AT.json'

export const defaultLocale = 'en-GB'
export const localeOptions = [defaultLocale, 'de-DE', 'de-AT'] as const
export type LocaleOption = typeof localeOptions[number]
export function isLocaleOption(value: string): value is LocaleOption {
  return localeOptions.some((option) => option === value)
}

export const i18n = createI18n({
  locale: defaultLocale,
  fallbackLocale: 'en-GB',
  messages: {
    'en-GB': enGB,
    'de-DE': deDE,
    'de-AT': deAT,
  },
  legacy: false,
})
