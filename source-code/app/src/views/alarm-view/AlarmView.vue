<script setup lang="ts">
import PrimaryButton from '@/components/ui/buttons/PrimaryButton.vue'
import { besAirService } from '@/services/bes-air-rest.service'

async function alarm() {
  await besAirService.alarm()
}
</script>

<template>
  <div class="flex items-center justify-center">
    <PrimaryButton @click="alarm">Alarm</PrimaryButton>
  </div>
</template>
