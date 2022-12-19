<script setup lang="ts">
import SecondaryButton from './SecondaryButton.vue'
</script>

<template>
  <div @click="$router.back()">
    <SecondaryButton>
      <div class="flex gap-2 items-center">
        <i class="material-icons">arrow_back</i>
        <span class="pr-2">{{ $t('navigation.back.label') }}</span>
      </div>
    </SecondaryButton>
  </div>
</template>
