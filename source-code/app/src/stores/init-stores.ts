import { useBesnStore } from './besn.store'
import { useLocaleStore } from './locale.store'

export function initStores() {
  useLocaleStore().initFromLocalStorage()
  useBesnStore().connect()
}
