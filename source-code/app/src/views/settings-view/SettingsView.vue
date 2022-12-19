<script setup lang="ts">
import LanguageSettings from '@/views/settings-view/LanguageSettings.vue'
import ConnectionSettings from './ConnectionSettings.vue'
import BackButton from '@/components/ui/buttons/BackButton.vue'
import HomeButton from '@/components/ui/buttons/HomeButton.vue'
</script>

<template>
  <div>
    <div class="flex items-center gap-4 flex-wrap">
      <h1 class="text-4xl">{{ $t('view.settings.heading.label') }}</h1>
      <HomeButton />
    </div>

    <LanguageSettings class="mt-6" />
    <ConnectionSettings class="mt-6" />
  </div>
</template>
