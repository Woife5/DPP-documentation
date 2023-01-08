import axios, { type AxiosResponse } from 'axios'
import type {
  BesAirService,
  GetBesnStateData,
  GetLanguageData,
  SetLanguageData,
} from './bes-air.service'

export class BesAirRestService implements BesAirService {
  public url = ''

  public get apiUrl() {
    return `${this.url}/api`
  }

  public async isAlive(): Promise<void> {
    await axios.get(`${this.apiUrl}/alive`)
  }

  public async startBesn(): Promise<void> {
    await axios.post(`${this.apiUrl}/start`)
  }

  public async stopBesn(): Promise<void> {
    await axios.post(`${this.apiUrl}/stop`)
  }

  public async getBesnState(): Promise<AxiosResponse<GetBesnStateData>> {
    return await axios.get(`${this.apiUrl}/state`)
  }

  public async getLanguage(): Promise<AxiosResponse<GetLanguageData>> {
    return await axios.get(`${this.apiUrl}/lang`)
  }

  public async setLanguage(
    language: string
  ): Promise<AxiosResponse<SetLanguageData>> {
    return await axios.post(`${this.apiUrl}/lang`, { language })
  }
}
