<script setup lang="ts">
import LanguageSettings from '@/views/settings-view/LanguageSettings.vue'
import ConnectionSettings from './ConnectionSettings.vue'
</script>

<template>
  <div>
    <h1 class="text-4xl">{{ $t('view.settings.heading.label') }}</h1>
    <LanguageSettings class="mt-6" />
    <ConnectionSettings class="mt-6" />
  </div>
</template>
