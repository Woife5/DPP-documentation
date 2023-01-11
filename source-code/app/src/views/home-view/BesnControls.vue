<script setup lang="ts">
import { useMutation, useQuery, useQueryClient } from 'vue-query'
import BigFatButton from './BigFatButton.vue'
import TryReconnect from './TryReconnect.vue'
import { computed } from 'vue'
import { besAirService, type BesnState } from '@/services/bes-air-rest.service'
import ConnectionPending from '@/components/ui/connection/ConnectionPending.vue'

export type BesnButtonState = BesnState | 'offline'

const queryClient = useQueryClient()

const { data, isLoading, isFetching, isError } = useQuery('q-besn-state', () =>
  besAirService.getBesnState()
)

const {
  mutate,
  isLoading: isLoadingMutation,
  isError: isErrorMutation,
} = useMutation(
  'm-besn-state',
  () => {
    if (data.value?.data.state === 'on') {
      return besAirService.stopBesn()
    }
    return besAirService.startBesn()
  },
  {
    onSuccess: () => {
      queryClient.invalidateQueries('q-besn-state')
    },
  }
)

const isPending = computed(
  () => isLoading.value || isFetching.value || isLoadingMutation.value
)

const besnButtonState = computed<BesnButtonState>(() => {
  if (isError.value || isErrorMutation.value) {
    return 'offline'
  }
  return data.value?.data.state ?? 'offline'
})

function onBigFatButtonClick() {
  mutate()
}

function onTryReconnectClick() {
  queryClient.invalidateQueries('q-besn-state')
}
</script>

<template>
  <div class="flex flex-col items-center gap-y-2">
    <BigFatButton
      :state="besnButtonState"
      :pending="isPending"
      @change="onBigFatButtonClick"
    />
    <TryReconnect
      v-if="!isPending"
      :state="besnButtonState"
      @click="onTryReconnectClick"
    />
    <ConnectionPending v-if="isFetching" />
  </div>
</template>
