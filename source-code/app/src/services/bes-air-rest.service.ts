import axios from 'axios'
import type { BesAirService, GetBesnStateResponse } from './bes-air.service'

export class BesAirRestService implements BesAirService {
  private url = 'http://192.168.43.158/api'

  public async startBesn(): Promise<void> {
    await axios.post(`${this.url}/start`)
  }

  public async stopBesn(): Promise<void> {
    await axios.post(`${this.url}/stop`)
  }

  public async getBesnState(): Promise<GetBesnStateResponse> {
    return await axios.get(`${this.url}/state`)
  }
}
