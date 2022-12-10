import type { BesAirService, GetBesnStateResponse } from './bes-air.service'

export class BesAirMockService implements BesAirService {
  private readonly serverData = {
    besnState: 'off' as 'on' | 'off',
  }
  private readonly failChance = 0.2
  public url = ''

  public async startBesn(): Promise<void> {
    if (Math.random() < this.failChance) throw new Error('Failed to start besn')
    this.serverData.besnState = 'on'
  }
  public async stopBesn(): Promise<void> {
    if (Math.random() < this.failChance) throw new Error('Failed to start besn')
    this.serverData.besnState = 'off'
  }

  public async getBesnState(): Promise<GetBesnStateResponse> {
    return {
      state: this.serverData.besnState,
    }
  }
}
