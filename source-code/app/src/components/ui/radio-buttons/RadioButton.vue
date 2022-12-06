<script setup lang="ts">
defineProps<{
  id: string
  label: string
  name: string
  value: string
  checked: boolean
}>()
</script>

<template>
  <div
    class="flex items-center gap-1 rounded-full pl-3 pr-4 py-1 dark:hover:bg-slate-600"
    :class="{ 'dark:bg-slate-700': checked }"
  >
    <input
      type="radio"
      :id="id"
      :name="name"
      :value="value"
      :checked="checked"
    />
    <label :for="id">{{ label }}</label>
  </div>
</template>

<style scoped>
input[type='radio'] {
  border-radius: 0;
}
</style>
