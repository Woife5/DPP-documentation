<script setup lang="ts">
import AppLanguageSettings from '@/views/settings-view/AppLanguageSettings.vue'
import ConnectionSettings from './ConnectionSettings.vue'
import AudioLanguageSettings from './AudioLanguageSettings.vue'
</script>

<template>
  <div>
    <h1 class="text-4xl">{{ $t('view.settings.heading.label') }}</h1>
    <ConnectionSettings class="mt-6" />
    <AudioLanguageSettings class="mt-6" />
    <AppLanguageSettings class="mt-6" />
  </div>
</template>
