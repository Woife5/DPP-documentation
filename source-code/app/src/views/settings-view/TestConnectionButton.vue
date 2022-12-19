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
</script>

<template>
  <SecondaryButton>
    <div class="flex flex-wrap gap-2">
      <span>{{ $t('view.settings.connection.test-url.label') }}</span>
      <i v-if="icon != null" class="material-icons">{{ icon }}</i>
    </div>
  </SecondaryButton>
</template>
