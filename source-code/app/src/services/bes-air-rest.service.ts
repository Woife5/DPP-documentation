import axios from 'axios'
import type { BesAirService, GetBesnStateResponse } from './bes-air.service'

export class BesAirRestService implements BesAirService {
  public url = 'http://192.168.43.158/api'

  public get apiUrl() {
    return `${this.url}/api}`
  }

  public async startBesn(): Promise<void> {
    await axios.post(`${this.apiUrl}/start`)
  }

  public async stopBesn(): Promise<void> {
    await axios.post(`${this.apiUrl}/stop`)
  }

  public async getBesnState(): Promise<GetBesnStateResponse> {
    return await axios.get(`${this.apiUrl}/state`)
  }
}
