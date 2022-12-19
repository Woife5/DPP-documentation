<script setup lang="ts">
import BigFatButton from './BigFatButton.vue'
import { useBesnStore } from '@/stores/besn.store'
import TryReconnect from './TryReconnect.vue'
import { onMounted } from 'vue'

const besnStore = useBesnStore()

onMounted(() => besnStore.connect())

async function toggleButtonState() {
  await besnStore.toggleBesn()
}
</script>

<template>
  <div class="flex flex-col items-center gap-y-2">
    <BigFatButton
      :state="besnStore.besnState"
      :pending="besnStore.pending"
      @change="toggleButtonState"
    />
    <TryReconnect />
  </div>
</template>
