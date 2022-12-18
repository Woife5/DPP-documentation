<script setup lang="ts">
import SubtleButton from './ui/buttons/SubtleButton.vue'
</script>

<template>
  <header
    class="flex flex-col sm:flex-row justify-start sm:justify-between gap-y-2 items-center px-4 py-4"
  >
    <div class="flex justify-start">
      <RouterLink id="home-link" :to="{ name: 'home' }">
        <div class="flex flex-col items-center rounded-full">
          <h1 class="flex items-center gap-4">
            <span class="text-4xl font-righteous">{{ $t('app.title') }}</span>
            <i class="text-4xl material-icons"> cleaning_services </i>
          </h1>
          <div class="hidden sm:block">{{ $t('app.slogan') }}</div>
        </div>
      </RouterLink>
    </div>
    <div class="flex justify-end sm:justify-start gap-1">
      <RouterLink :to="{ name: 'led-settings' }">
        <SubtleButton>
          <div class="flex gap-2 items-center">
            <span>{{ $t('header.led-settings.label') }}</span>
            <i class="material-icons">lightbulb</i>
          </div>
        </SubtleButton>
      </RouterLink>
      <RouterLink :to="{ name: 'settings' }">
        <SubtleButton>
          <div class="flex gap-2 items-center">
            <span>{{ $t('header.settings.label') }}</span>
            <i class="material-icons">settings</i>
          </div>
        </SubtleButton>
      </RouterLink>
    </div>
  </header>
</template>

<style scoped>
a.router-link-active:not(#home-link) > * {
  @apply dark:bg-slate-700;
}

h1 {
  text-shadow: 1px 1px 2px hsl(222, 20%, 50%), 0 0 1em hsl(222, 20%, 70%),
    0 0 0.2em hsl(222, 20%, 70%);
}

@media (prefers-color-scheme: dark) {
  h1 {
    text-shadow: 1px 1px 2px hsl(222, 80%, 60%), 0 0 1em hsl(222, 40%, 40%),
      0 0 0.2em hsl(222, 40%, 40%);
  }
}
</style>
