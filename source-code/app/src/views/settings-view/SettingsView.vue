<script setup lang="ts">
import SecondaryButton from '@/components/ui/buttons/SecondaryButton.vue'
import { localeOptions } from '@/locales/i18n'
import { useLocaleStore } from '@/stores/locale.store'

const { $state, setLocale } = useLocaleStore()
</script>

<template>
  <div class="flex flex-col gap-8">
    <div class="flex items-center gap-4">
      <h1 class="text-4xl">Settings</h1>
      <RouterLink :to="{ name: 'home' }">
        <SecondaryButton>
          <div class="flex gap-2 items-center">
            <i class="material-icons">arrow_back</i>
            <span>Back</span>
          </div>
        </SecondaryButton>
      </RouterLink>
    </div>

    <div class="flex">
      <fieldset>
        <legend class="mb-2">
          <h1 class="flex items-center gap-2 text-2xl">
            <span>Language</span>
            <i class="material-icons">language</i>
          </h1>
        </legend>

        <div
          v-for="localeOption of localeOptions"
          @click="() => setLocale(localeOption)"
        >
          <input
            type="radio"
            :id="localeOption"
            name="language"
            :value="localeOption"
            :checked="localeOption === $state.selectedLocale"
          />
          <label :for="localeOption">{{ localeOption }}</label>
        </div>
      </fieldset>
    </div>
  </div>
</template>
