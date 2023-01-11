<script setup lang="ts">
import LoadingCircle from '../loading-spinners/LoadingCircle.vue'
</script>

<template>
  <div class="flex items-center gap-2 mt-2">
    <LoadingCircle class="border-yellow-600 dark:border-yellow-400 h-6 w-6" />
    <div class="text-light-warn dark:text-dark-warn">
      {{ $t('bes-air-service.pending') }}
    </div>
  </div>
</template>
