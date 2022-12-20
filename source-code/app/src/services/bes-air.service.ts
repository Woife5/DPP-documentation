import type { AxiosResponse } from 'axios'
import { BesAirRestService } from './bes-air-rest.service'

export interface BesAirService {
  url: string
  isAlive(): Promise<void>
  startBesn(): Promise<void>
  stopBesn(): Promise<void>
  getBesnState(): Promise<AxiosResponse<GetBesnStateResponse>>
}

export const besAirService: BesAirService = new BesAirRestService()

export type GetBesnStateResponse = {
  state: unknown
}
