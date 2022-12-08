import { BesAirMockService } from './bes-air-mock.service'
import { BesAirRestService } from './bes-air-rest.service'

export interface BesAirService {
  url: string
  startBesn(): Promise<void>
  stopBesn(): Promise<void>
  getBesnState(): Promise<GetBesnStateResponse>
}

export const besAirService: BesAirService = new BesAirMockService()
// export const besAirService: BesAirService = new BesAirRestService()

export type GetBesnStateResponse = {
  state: 'on' | 'off'
}
