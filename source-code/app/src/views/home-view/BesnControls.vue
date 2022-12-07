<script setup lang="ts">
// import { besAirService } from '@/services/bes-air.service'
import { ref } from 'vue'
import BigFatButton from './BigFatButton.vue'
import { useBesnStore } from '@/stores/besn.store'

const { $state, toggleBesn } = useBesnStore()

async function toggleButtonState() {
  await toggleBesn()
  // if (besnActivated.value) {
  //   const res = await besAirService.startBesn()
  //   if (res.status === 200) {
  //     console.log('Besn is now ON')
  //   } else {
  //     console.error(res.status)
  //   }
  // } else {
  //   const res = await besAirService.stopBesn()
  //   if (res.status === 200) {
  //     console.log('Besn is now OFF')
  //   } else {
  //     console.error(res.status)
  //   }
  // }
}
</script>

<template>
  <div>
    <BigFatButton :state="$state.besnState" @change="toggleButtonState" />
  </div>
</template>
