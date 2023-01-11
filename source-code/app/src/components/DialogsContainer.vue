<script setup lang="ts">
import { onMounted, ref } from 'vue'
import DisclaimerDialog from './ui/dialogs/DisclaimerDialog.vue'

const disclaimerDialog = ref<InstanceType<typeof DisclaimerDialog>>()

// onMounted(() => disclaimerDialog.value?.open())
</script>

<template>
  <DisclaimerDialog ref="disclaimerDialog" />
</template>
