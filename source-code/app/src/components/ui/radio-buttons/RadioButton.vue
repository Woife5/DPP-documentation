<script setup lang="ts">
defineProps<{
  id: string
  label: string
  name: string
  value: string
  checked: boolean
  disabled?: boolean
}>()

const emits = defineEmits<{
  (e: 'change'): void
}>()

function onInputChange(_event: Event) {
  emits('change')
}
</script>

<template>
  <div
    class="flex items-center gap-1 rounded-full pl-3 pr-4 py-1"
    :class="{
      'bg-slate-300 dark:bg-slate-700': checked,
      'hover:bg-slate-400 dark:hover:bg-slate-600 cursor-pointer':
        disabled !== true,
    }"
  >
    <input
      type="radio"
      :id="id"
      :name="name"
      :value="value"
      :checked="checked"
      :disabled="disabled"
      :class="{ 'cursor-pointer': disabled !== true }"
      @change="onInputChange"
    />
    <label :for="id" :class="{ 'cursor-pointer': disabled !== true }">
      {{ label }}
    </label>
  </div>
</template>

<style scoped>
input[type='radio'] {
  border-radius: 0;
}
</style>
