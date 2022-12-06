<script setup lang="ts">
import SecondaryButton from '@/components/ui/buttons/SecondaryButton.vue'
import RadioButton from '@/components/ui/radio-buttons/RadioButton.vue'
import { localeOptions } from '@/locales/i18n'
import { useLocaleStore } from '@/stores/locale.store'

const { $state, setLocale } = useLocaleStore()
</script>

<template>
  <div>
    <div class="flex items-center gap-4">
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

    <div class="mt-6">
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
            :label="$t(`locale.option.${localeOption}.label`)"
            name="language"
            :value="localeOption"
            :checked="localeOption === $state.selectedLocale"
          />
        </div>
      </fieldset>
    </div>
  </div>
</template>
