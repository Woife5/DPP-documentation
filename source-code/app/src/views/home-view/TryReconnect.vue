<script setup lang="ts">
import { useBesnStore } from '@/stores/besn.store'
import ReconnectButton from './ReconnectButton.vue'

const { $state, connect } = useBesnStore()

function onReconnectClick() {
  connect()
}
</script>

<template>
  <ReconnectButton
    v-if="$state.besnState === 'offline'"
    @click="onReconnectClick"
  />
</template>
