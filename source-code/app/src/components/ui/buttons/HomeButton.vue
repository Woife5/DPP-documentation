<script setup lang="ts">
import SecondaryButton from './SecondaryButton.vue'
</script>

<template>
  <RouterLink :to="{ name: 'home' }">
    <SecondaryButton>
      <div class="flex gap-2 items-center">
        <i class="material-icons">home</i>
        <span class="pr-2">{{ $t('navigation.home.label') }}</span>
      </div>
    </SecondaryButton>
  </RouterLink>
</template>
