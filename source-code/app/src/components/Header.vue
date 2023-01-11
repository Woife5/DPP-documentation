<script setup lang="ts">
import SubtleButton from './ui/buttons/SubtleButton.vue'
</script>

<template>
  <header class="mx-auto flex flex-col items-center gap-y-4 mt-4">
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
    <div class="flex flex-wrap gap-1">
      <RouterLink :to="{ name: 'home' }">
        <SubtleButton>
          <div class="flex gap-2 items-center">
            <i class="material-icons">home</i>
            <span class="hidden sm:block">{{
              $t('navigation.home.label')
            }}</span>
          </div>
        </SubtleButton>
      </RouterLink>
      <RouterLink :to="{ name: 'settings' }">
        <SubtleButton>
          <div class="flex gap-2 items-center">
            <i class="material-icons">settings</i>
            <span class="hidden sm:block">{{
              $t('header.settings.label')
            }}</span>
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
