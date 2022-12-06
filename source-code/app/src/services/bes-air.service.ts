import axios from 'axios'

class BesAirService {
  private url = 'http://192.168.43.158/api'

  public async startBesn() {
    return await axios.post(`${this.url}/start`)
  }

  public async stopBesn() {
    return await axios.post(`${this.url}/stop`)
  }
}

export const besAirService = new BesAirService()
