<script setup lang="ts">
import SubtleButton from './ui/buttons/SubtleButton.vue'
</script>

<template>
  <header class="flex items-center mt-6">
    <div class="w-2/12 flex justify-center"></div>
    <div class="w-8/12">
      <RouterLink :to="{ name: 'home' }">
        <div class="flex flex-col items-center">
          <h1 class="flex items-center gap-4">
            <span class="text-4xl font-righteous">{{ $t('app.title') }}</span>
            <i class="hidden sm:block text-4xl material-icons"
              >cleaning_services</i
            >
          </h1>
          <div class="hidden sm:block">{{ $t('app.slogan') }}</div>
        </div>
      </RouterLink>
    </div>
    <div class="w-2/12 flex justify-center">
      <RouterLink
        :to="{ name: $route.name != 'settings' ? 'settings' : 'home' }"
      >
        <SubtleButton>
          <div class="flex gap-2 items-center">
            <span class="hidden sm:block">{{
              $t('header.settings.label')
            }}</span>
            <i class="material-icons">settings</i>
          </div></SubtleButton
        >
      </RouterLink>
    </div>
  </header>
</template>

<style scoped>
h1 {
  text-shadow: 1px 1px 2px hsl(222, 80%, 60%), 0 0 1em hsl(222, 40%, 40%),
    0 0 0.2em hsl(222, 40%, 40%);
}
</style>
