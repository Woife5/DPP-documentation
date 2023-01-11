import qs from 'qs'

class BesAirRestService {
  public url = ''

  public get apiUrl() {
    return `${this.url}/api`
  }

  public async isAlive(): Promise<Response> {
    return fetch(`${this.apiUrl}/alive`, {
      method: 'GET',
    })
  }

  public async getBesnState(): Promise<
    ResponseWithData<{
      state: BesnState
    }>
  > {
    const res = await fetch(`${this.apiUrl}/state`, {
      method: 'GET',
    })
    return {
      response: res,
      data: await res.json(),
    }
  }

  public async startBesn(): Promise<Response> {
    return fetch(`${this.apiUrl}/start`, {
      method: 'POST',
    })
  }

  public async stopBesn(): Promise<Response> {
    return fetch(`${this.apiUrl}/stop`, {
      method: 'POST',
    })
  }

  public async getLanguage(): Promise<
    ResponseWithData<{
      lang: BesnLanguageOption
    }>
  > {
    const res = await fetch(`${this.apiUrl}/language`, {
      method: 'GET',
    })
    return {
      response: res,
      data: await res.json(),
    }
  }

  public async setLanguage(language: string): Promise<
    ResponseWithData<{
      lang: BesnLanguageOption
    }>
  > {
    const res = await fetch(`${this.apiUrl}/language`, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/x-www-form-urlencoded',
      },
      body: qs.stringify({ lang: language }),
    })
    return {
      response: res,
      data: await res.json(),
    }
  }

  public async alarm(): Promise<Response> {
    return fetch(`${this.apiUrl}/alarm`, {
      method: 'POST',
    })
  }
}

export const besAirService = new BesAirRestService()

export type ResponseWithData<T> = {
  response: Response
  data: T
}
export type BesnState = 'on' | 'off'
export const besnLanguageOptions = ['de', 'us', 'ru', 'jp', 'ch'] as const
export type BesnLanguageOption = (typeof besnLanguageOptions)[number]
