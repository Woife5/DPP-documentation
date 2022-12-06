<script setup lang="ts">
import { besAirService } from '@/services/bes-air.service'
import { computed, ref } from 'vue'

const buttonState = ref<'on' | 'off'>('off')

const classes = computed(() => {
  return {
    'bg-gradient-to-r from-red-600 to-red-800 hover:from-red-500 hover:to-red-700':
      buttonState.value === 'on',
    'bg-gradient-to-r from-green-600 to-green-800 hover:from-green-500 hover:to-green-700 motion-safe:animate-wiggle':
      buttonState.value === 'off',
  }
})

async function toggleButtonState() {
  buttonState.value = buttonState.value === 'on' ? 'off' : 'on'
  if (buttonState.value === 'on') {
    const res = await besAirService.startBesn()
    if (res.status === 200) {
      console.log('Besn is now ON')
    } else {
      console.error(res.status)
    }
  } else {
    const res = await besAirService.stopBesn()
    if (res.status === 200) {
      console.log('Besn is now OFF')
    } else {
      console.error(res.status)
    }
  }
}
</script>

<template>
  <button
    type="button"
    class="p-20 rounded-full shadow-md transition-all duration-200 uppercase"
    @click="toggleButtonState"
    :class="classes"
  >
    <div class="w-10 h-10 flex justify-center items-center">
      <span v-if="buttonState === 'on'">off</span>
      <span v-else>on</span>
    </div>
  </button>
</template>
