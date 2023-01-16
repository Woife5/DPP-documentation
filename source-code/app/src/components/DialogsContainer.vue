<script setup lang="ts">
import { onMounted, ref } from 'vue'
import DisclaimerDialog from './ui/dialogs/DisclaimerDialog.vue'

const disclaimerDialog = ref<InstanceType<typeof DisclaimerDialog>>()

onMounted(() => {
  disclaimerDialog.value?.open()
})
</script>

<template>
  <DisclaimerDialog
    header-translation-key="app.cookie-disclaimer.heading"
    content-translation-key="app.cookie-disclaimer.content"
    ref="disclaimerDialog"
  />
</template>
