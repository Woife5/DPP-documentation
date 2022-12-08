<script setup lang="ts">
// import { besAirService } from '@/services/bes-air.service'
import BigFatButton from './BigFatButton.vue'
import { useBesnStore } from '@/stores/besn.store'
import TryReconnect from './TryReconnect.vue'

const { $state, toggleBesn } = useBesnStore()

async function toggleButtonState() {
  await toggleBesn()
}
</script>

<template>
  <div class="flex flex-col items-center gap-y-2">
    <BigFatButton :state="$state.besnState" @change="toggleButtonState" />
    <TryReconnect />
  </div>
</template>
