export type FlagKey = 'data-collection-accepted' | 'cookies-accepted'

const flags: { [key in FlagKey]?: boolean } = {}

export class FlagService {
  public static getFlag(key: FlagKey): boolean {
    return flags[key] ?? false
    // return localStorage.getItem(key) === 'true'
  }

  public static setFlag(key: FlagKey, value: boolean): void {
    flags[key] = value
    // localStorage.setItem(key, value.toString())
  }
}
