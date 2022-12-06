<script setup lang="ts">
import SecondaryButton from '@/components/ui/buttons/SecondaryButton.vue'
</script>

<template>
  <div>
    <div class="flex items-center gap-4">
      <h1 class="text-4xl">Settings</h1>
      <RouterLink :to="{ name: 'home' }">
        <SecondaryButton>
          <div class="flex gap-2 items-center uppercase">
            <i class="material-icons">arrow_back</i>
            <span>Back</span>
          </div>
        </SecondaryButton>
      </RouterLink>
    </div>
  </div>
</template>
