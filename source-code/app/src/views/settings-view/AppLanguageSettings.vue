<script setup lang="ts">
import RadioButton from '@/components/ui/radio-buttons/RadioButton.vue'
import { localeOptions } from '@/locales/i18n'
import { useLocaleStore } from '@/stores/locale.store'

const localeStore = useLocaleStore()
</script>

<template>
  <article>
    <fieldset>
      <legend class="mb-2">
        <h1 class="flex items-center gap-2 text-2xl">
          <span>{{ $t('view.settings.language.heading.label') }}</span>
          <i class="material-icons">language</i>
        </h1>
      </legend>

      <div class="flex flex-col items-start gap-y-1">
        <RadioButton
          v-for="localeOption of localeOptions"
          :id="`app-locale-${localeOption}`"
          :key="`app-locale-${localeOption}`"
          :label="$t(`app-locale.${localeOption}.label`)"
          name="app-locale"
          :value="localeOption"
          @click="() => (localeStore.selectedLocale = localeOption)"
          :checked="localeOption === localeStore.selectedLocale"
          :title="localeOption"
        />
      </div>
    </fieldset>
  </article>
</template>
