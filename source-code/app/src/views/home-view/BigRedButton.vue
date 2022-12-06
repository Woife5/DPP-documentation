<script setup lang="ts">
import { besAirService } from '@/services/bes-air.service'
import { computed, ref } from 'vue'

const besnState = ref<'on' | 'off'>('off')

const classes = computed(() => {
  return {
    'bg-gradient-to-r from-red-600 to-red-800 hover:from-red-500 hover:to-red-700 motion-safe:animate-vibrate':
      besnState.value === 'on',
    'bg-gradient-to-r from-green-600 to-green-800 hover:from-green-500 hover:to-green-700':
      besnState.value === 'off',
  }
})

async function toggleButtonState() {
  besnState.value = besnState.value === 'on' ? 'off' : 'on'
  if (besnState.value === 'on') {
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
    <div
      class="w-10 h-10 flex justify-center items-center text-4xl font-oxanium"
    >
      <span> <i class="material-icons">power_setting_new</i></span>
    </div>
  </button>
</template>
