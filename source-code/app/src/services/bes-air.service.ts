import type { AxiosResponse } from 'axios'
import { BesAirRestService } from './bes-air-rest.service'

export interface BesAirService {
  url: string
  isAlive(): Promise<void>
  startBesn(): Promise<void>
  stopBesn(): Promise<void>
  getBesnState(): Promise<AxiosResponse<GetBesnStateData>>
  getLanguage(): Promise<AxiosResponse<GetLanguageData>>
  setLanguage(language: string): Promise<AxiosResponse<SetLanguageData>>
}

export const besAirService: BesAirService = new BesAirRestService()

export type GetBesnStateData = {
  state: unknown
}

export const besnLanguageOptions = ['de', 'us', 'ru', 'jp', 'ch'] as const
export type BesnLanguageOption = typeof besnLanguageOptions[number]

export type GetLanguageData = {
  lang: BesnLanguageOption
}
export type SetLanguageData = {
  lang: BesnLanguageOption
}
