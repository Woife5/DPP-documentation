<script setup lang="ts">
import { useMutation, useQuery, useQueryClient } from 'vue-query'
import BigFatButton from './BigFatButton.vue'
import TryReconnect from './TryReconnect.vue'
import { computed } from 'vue'
import { besAirService, type BesnState } from '@/services/bes-air-rest.service'

export type BesnButtonState = BesnState | 'offline'

const queryClient = useQueryClient()

const { data, isLoading, isFetching, isError } = useQuery('q-besn-state', () =>
  besAirService.getBesnState()
)

const { mutate } = useMutation(
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

const isPending = isLoading || isFetching
const besnButtonState = computed<BesnButtonState>(
  () => data.value?.data.state ?? 'offline'
)

function onBigFatButtonClick() {
  mutate()
}
</script>

<template>
  <div class="flex flex-col items-center gap-y-2">
    <BigFatButton
      :state="besnButtonState"
      :pending="isPending"
      @change="onBigFatButtonClick"
    />
    <TryReconnect v-if="!isPending" :state="besnButtonState" />
  </div>
</template>
