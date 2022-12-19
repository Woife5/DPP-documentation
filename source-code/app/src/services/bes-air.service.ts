import type { AxiosResponse } from 'axios'
import { BesAirMockService } from './bes-air-mock.service'
import { BesAirRestService } from './bes-air-rest.service'

export interface BesAirService {
  url: string
  startBesn(): Promise<void>
  stopBesn(): Promise<void>
  getBesnState(): Promise<AxiosResponse<GetBesnStateResponse>>
}

// export const besAirService: BesAirService = import.meta.env.PROD
//   ? new BesAirRestService()
//   : new BesAirMockService()

export const besAirService: BesAirService = new BesAirRestService()

export type GetBesnStateResponse = {
  state: unknown
}
