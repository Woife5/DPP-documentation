<script setup lang="ts">
import RadioButton from '@/components/ui/radio-buttons/RadioButton.vue'
import { localeOptions } from '@/locales/i18n'
import { useLocaleStore } from '@/stores/locale.store'

const { $state, setLocale } = useLocaleStore()
</script>

<template>
  <div>
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
          @click="() => setLocale(localeOption)"
          :id="localeOption"
          :label="$t(`locale.${localeOption}.label`)"
          name="language"
          :value="localeOption"
          :checked="localeOption === $state.selectedLocale"
        />
      </div>
    </fieldset>
  </div>
</template>
