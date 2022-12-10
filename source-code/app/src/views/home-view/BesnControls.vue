<script setup lang="ts">
import BigFatButton from './BigFatButton.vue'
import { useBesnStore } from '@/stores/besn.store'
import TryReconnect from './TryReconnect.vue'

const besnStore = useBesnStore()

async function toggleButtonState() {
  await besnStore.toggleBesn()
}
</script>

<template>
  <div class="flex flex-col items-center gap-y-2">
    <BigFatButton :state="besnStore.besnState" @change="toggleButtonState" />
    <TryReconnect />
  </div>
</template>
