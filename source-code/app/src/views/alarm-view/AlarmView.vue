<script setup lang="ts">
import PrimaryButton from '@/components/ui/buttons/PrimaryButton.vue'
import ConnectionError from '@/components/ui/connection/ConnectionError.vue'
import ConnectionPending from '@/components/ui/connection/ConnectionPending.vue'
import { besAirService } from '@/services/bes-air-rest.service'
import { useMutation } from 'vue-query'

const { mutate, isLoading, isError } = useMutation('m-alarm', () =>
  besAirService.alarm()
)

async function triggerAlarm() {
  mutate()
}
</script>

<template>
  <div class="flex flex-col items-center">
    <PrimaryButton class="flex gap-2" @click="triggerAlarm">
      <div>Bes Air Alarm</div>
      <i class="material-icons">cleaning_services</i>
    </PrimaryButton>
    <ConnectionPending v-if="isLoading" />
    <ConnectionError v-if="isError" />
  </div>
</template>
