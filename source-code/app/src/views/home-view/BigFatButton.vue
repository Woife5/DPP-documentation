<script setup lang="ts">
import LoadingCircle from '@/components/ui/loading-spinners/LoadingCircle.vue'
import type { BesnState } from '@/stores/besn.store'
import { computed, ref } from 'vue'

const props = defineProps<{
  state: BesnState
  pending: boolean
}>()

const emits = defineEmits<{
  (e: 'change'): void
}>()

const classes = computed(() => {
  console.log('Besn state', props.state)
  return {
    'from-red-300 to-red-500 hover:from-red-400 hover:to-red-600 motion-safe:animate-shake':
      props.state === 'on',
    'dark:from-red-600 dark:to-red-800 dark:hover:from-red-500 dark:hover:to-red-700':
      props.state === 'on',
    'from-green-300 to-green-500 hover:from-green-400 hover:to-green-600':
      props.state === 'off',
    'dark:from-green-600 dark:to-green-800 dark:hover:from-green-500 dark:hover:to-green-700':
      props.state === 'off',
    'from-gray-300 to-gray-400 dark:from-gray-500 dark:to-gray-600':
      props.state === 'offline',
  }
})

function onButtonClick() {
  emits('change')
}
</script>

<template>
  <div class="flex flex-col items-center gap-y-2">
    <button
      ref="buttonEl"
      type="button"
      class="p-20 rounded-full shadow-md transition-all duration-200 uppercase bg-gradient-to-br select-none"
      :disabled="state === 'offline'"
      @click="onButtonClick"
      :class="classes"
    >
      <div class="w-10 h-10 flex justify-center items-center">
        <LoadingCircle v-if="pending" />
        <i v-else class="text-5xl material-icons">power_settings_new</i>
      </div>
    </button>
  </div>
</template>
