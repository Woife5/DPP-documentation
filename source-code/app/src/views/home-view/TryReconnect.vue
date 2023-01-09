<script setup lang="ts">
import ReconnectButton from './ReconnectButton.vue'
import type { BesnButtonState } from './BesnControls.vue'

defineProps<{
  state: BesnButtonState
}>()
</script>

<template>
  <ReconnectButton v-if="state === 'offline'" />
</template>
