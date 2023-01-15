import type { Ref } from 'vue'

export type QueryDataRef<T extends Ref<any>> = Exclude<
  T,
  Ref<undefined>
>['value']
