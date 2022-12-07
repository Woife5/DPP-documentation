import type { BesAirService, GetBesnStateResponse } from './bes-air.service'

export class BesAirMockService implements BesAirService {
  private serverData = {
    besnState: 'off' as 'on' | 'off',
  }

  public async startBesn(): Promise<void> {
    this.serverData.besnState = 'on'
  }
  public async stopBesn(): Promise<void> {
    this.serverData.besnState = 'off'
  }

  public async getBesnState(): Promise<GetBesnStateResponse> {
    return {
      state: this.serverData.besnState,
    }
  }
}
