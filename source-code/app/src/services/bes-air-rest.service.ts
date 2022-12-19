import axios, { type AxiosResponse } from 'axios'
import type { BesAirService, GetBesnStateResponse } from './bes-air.service'

export class BesAirRestService implements BesAirService {
  public url = ''

  public get apiUrl() {
    return `${this.url}/api`
  }

  public async startBesn(): Promise<void> {
    await axios.post(`${this.apiUrl}/start`)
  }

  public async stopBesn(): Promise<void> {
    await axios.post(`${this.apiUrl}/stop`)
  }

  public async getBesnState(): Promise<AxiosResponse<GetBesnStateResponse>> {
    return await axios.get(`${this.apiUrl}/state`)
  }
}
