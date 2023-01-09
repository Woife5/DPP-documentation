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
classMap.set('pending', 'text-yellow-600 dark:text-yellow-400')
classMap.set('success', 'text-green-600 dark:text-green-400')
classMap.set('fail', 'text-red-600 dark:text-red-400')
const classes = computed(() => classMap.get(props.state))
</script>

<template>
  <SecondaryButton>
    <div class="flex flex-wrap gap-2">
      <span>{{ $t('view.settings.connection.test-url.label') }}</span>
      <i v-if="icon != null" class="material-icons" :class="classes">
        {{ icon }}
      </i>
    </div>
  </SecondaryButton>
</template>
