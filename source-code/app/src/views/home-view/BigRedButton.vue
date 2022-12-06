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
    'bg-gradient-to-r from-red-600 to-red-800 hover:from-red-500 hover:to-red-700 motion-safe:animate-shake':
      props.activated,
    'bg-gradient-to-r from-green-600 to-green-800 hover:from-green-500 hover:to-green-700':
      !props.activated,
  }
})
</script>

<template>
  <button
    ref="buttonEl"
    type="button"
    class="p-20 rounded-full shadow-md transition-all duration-200 uppercase"
    @click="$emit('change')"
    :class="classes"
  >
    <div class="w-10 h-10 flex justify-center items-center">
      <i class="text-5xl material-icons">power_settings_new</i>
    </div>
  </button>
</template>
