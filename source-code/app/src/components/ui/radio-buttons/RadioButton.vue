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
    class="flex items-center gap-1 rounded-full pl-3 pr-4 py-1 hover:bg-slate-400 dark:hover:bg-slate-600 cursor-pointer"
    :class="{ 'bg-slate-300 dark:bg-slate-700': checked }"
  >
    <input
      type="radio"
      :id="id"
      :name="name"
      :value="value"
      :checked="checked"
      class="cursor-pointer"
    />
    <label :for="id" class="cursor-pointer">{{ label }}</label>
  </div>
</template>

<style scoped>
input[type='radio'] {
  border-radius: 0;
}
</style>
