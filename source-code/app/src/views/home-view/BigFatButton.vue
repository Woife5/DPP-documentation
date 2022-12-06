<script setup lang="ts">
import { computed, ref } from 'vue'

const props = defineProps<{
  activated: boolean
}>()

defineEmits<{
  (e: 'change'): void
}>()

const classes = computed(() => {
  return {
    'from-red-300 to-red-500 hover:from-red-400 hover:to-red-600 motion-safe:animate-shake':
      props.activated,
    'dark:from-red-600 dark:to-red-800 dark:hover:from-red-500 dark:hover:to-red-700':
      props.activated,
    'from-green-300 to-green-500 hover:from-green-400 hover:to-green-600':
      !props.activated,
    'dark:from-green-600 dark:to-green-800 dark:hover:from-green-500 dark:hover:to-green-700':
      !props.activated,
  }
})
</script>

<template>
  <button
    ref="buttonEl"
    type="button"
    class="p-20 rounded-full shadow-md transition-all duration-200 uppercase bg-gradient-to-r"
    @click="$emit('change')"
    :class="classes"
  >
    <div class="w-10 h-10 flex justify-center items-center">
      <i class="text-5xl material-icons">power_settings_new</i>
    </div>
  </button>
</template>
