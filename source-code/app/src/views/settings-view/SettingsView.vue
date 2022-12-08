<script setup lang="ts">
import SecondaryButton from '@/components/ui/buttons/SecondaryButton.vue'
import LanguageSettings from '@/views/settings-view/LanguageSettings.vue'
import ConnectionSettings from './ConnectionSettings.vue'
</script>

<template>
  <div>
    <div class="flex items-center gap-4 flex-wrap">
      <h1 class="text-4xl">{{ $t('view.settings.heading.label') }}</h1>
      <RouterLink :to="{ name: 'home' }">
        <SecondaryButton>
          <div class="flex gap-2 items-center">
            <i class="material-icons">arrow_back</i>
            <span class="pr-2">{{ $t('navigation.back.label') }}</span>
          </div>
        </SecondaryButton>
      </RouterLink>
    </div>

    <LanguageSettings class="mt-6" />
    <ConnectionSettings class="mt-6" />
  </div>
</template>
