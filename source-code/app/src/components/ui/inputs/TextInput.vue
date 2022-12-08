<script setup lang="ts">
import { resolveValue } from '@intlify/core-base'

defineProps<{
  id: string
  name: string
  value?: string
  label?: string
  placeholder?: string
}>()

const emits = defineEmits<{
  (e: 'input', value: string): void
}>()

function onInputChange(event: Event) {
  emits('input', (event.target as HTMLInputElement).value)
}
</script>

<template>
  <div class="flex flex-col">
    <label :for="id">{{ label }}</label>
    <input
      class="px-3 py-2 bg-slate-300 focus-visible:bg-slate-400 dark:bg-slate-700 dark:focus-visible:bg-slate-600 rounded-sm transition-colors duration-200"
      :id="id"
      type="text"
      :name="name"
      :placeholder="placeholder"
      :value="value"
      @input="onInputChange"
    />
  </div>
</template>
