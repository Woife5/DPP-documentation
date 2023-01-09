<script setup lang="ts">
import SecondaryButton from '@/components/ui/buttons/SecondaryButton.vue'
import { computed } from 'vue'

export type TestState = 'unset' | 'pending' | 'success' | 'fail'

const props = defineProps<{
  state: TestState
}>()

const iconMap = new Map<TestState, string | null>()
iconMap.set('unset', null)
iconMap.set('pending', 'pending')
iconMap.set('success', 'check_circle')
iconMap.set('fail', 'error')
const icon = computed(() => iconMap.get(props.state))

const classMap = new Map<TestState, string>()
classMap.set('pending', 'text-light-warn dark:text-dark-warn')
classMap.set('success', 'text-light-success dark:text-dark-success')
classMap.set('fail', 'text-light-error dark:text-dark-error')
const classes = computed(() => classMap.get(props.state))
</script>

<template>
  <i v-if="icon != null" class="material-icons" :class="classes">
    {{ icon }}
  </i>
</template>
