<script setup lang="ts">
import HomeButton from '@/components/ui/buttons/HomeButton.vue'
import RadioButton from '@/components/ui/radio-buttons/RadioButton.vue'
import { useLocalStorage } from '@vueuse/core'
import type { Color } from 'csstype'
import { ref, computed } from 'vue'

const selectedColor = useLocalStorage<Color>('led-color', '#ffffff')

const patternOptions = ['static', 'blink', 'pulse'] as const
type PatternOption = typeof patternOptions[number]
const selectedPattern = useLocalStorage<PatternOption>('led-pattern', 'static')

function onPatternClick(patternOption: PatternOption) {
  selectedPattern.value = patternOption
}
</script>

<template>
  <div>
    <div class="flex items-center gap-4 flex-wrap">
      <h1 class="text-4xl">{{ $t('view.led-settings.heading.label') }}</h1>
      <HomeButton />
    </div>

    <div class="mt-4 flex flex-col">
      <label for="led-color" class="text-2xl">LED Color</label>
      <input
        class="rounded-sm px-[2px] min-w-[60px] min-h-[40px] dark:bg-slate-700 dark:hover:bg-slate-600 translate-colors duration-200"
        v-model="selectedColor"
        type="color"
        name="led-color"
        id="led-color"
      />
      <div>Color: {{ selectedColor }}</div>
    </div>
    <fieldset class="mt-4">
      <legend class="mb-2">
        <h1 class="flex items-center gap-2 text-2xl">
          <span>{{ $t('view.led-settings.pattern.heading.label') }}</span>
          <i class="material-icons">pattern</i>
        </h1>
      </legend>

      <div class="flex flex-col items-start gap-y-1">
        <RadioButton
          v-for="patternOption of patternOptions"
          @click="() => onPatternClick(patternOption)"
          :id="patternOption"
          :label="$t(`view.led-settings.pattern.${patternOption}.label`)"
          name="led-pattern"
          :value="patternOption"
          :checked="patternOption === selectedPattern"
        />
      </div>
    </fieldset>
  </div>
</template>
