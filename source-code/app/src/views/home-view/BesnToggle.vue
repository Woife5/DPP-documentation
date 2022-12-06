<script setup lang="ts">
// import { besAirService } from '@/services/bes-air.service'
import { ref } from 'vue'
import BigRedButton from './BigRedButton.vue'

const besnActivated = ref(false)

async function toggleButtonState() {
  besnActivated.value = !besnActivated.value
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
    <BigRedButton
      ref="bigRedButtonEl"
      :activated="besnActivated"
      @change="toggleButtonState"
    />
  </div>
</template>
