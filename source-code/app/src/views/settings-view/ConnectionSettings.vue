<script setup lang="ts">
import TextInput from '@/components/ui/inputs/TextInput.vue'
import { useConnectionStore } from '@/stores/connection.store'
import ConnectionStatus, { type TestState } from './ConnectionStatus.vue'
import { besAirService } from '@/services/bes-air-rest.service'
import { onMounted, ref, computed } from 'vue'
import { useQuery, useQueryClient } from 'vue-query'

const connectionStore = useConnectionStore()
const queryClient = useQueryClient()

const showInvalidUrlError = ref(false)

connectionStore.$subscribe(() => {
  queryClient.invalidateQueries('is-alive')
})

const { data, isSuccess, isError, isFetching, isLoading } = useQuery(
  ['is-alive'],
  () => besAirService.isAlive()
)

const connectionTestState = computed<TestState>(() => {
  if (isLoading.value || isFetching.value) return 'pending'
  if (isSuccess.value) return 'success'
  if (isError.value) return 'fail'
  return 'unset'
})

function onUrlInput(value: string) {
  validateInput(value)
  connectionStore.connectionUrl = value
}

function validateInput(value: string) {
  const validator = /^https?:\/\/(localhost|[\w.-]{1,256})(:\d{1,4})?$/
  if (validator.test(value)) {
    showInvalidUrlError.value = false
  } else {
    showInvalidUrlError.value = true
  }
}
</script>

<template>
  <div>
    <fieldset>
      <legend class="mb-2">
        <h1 class="flex items-center gap-2 text-2xl">
          <span>{{ $t('view.settings.connection.heading.label') }}</span>
          <i class="material-icons">settings_remote</i>
        </h1>
      </legend>

      <div class="flex items-end gap-1">
        <TextInput
          class="grow"
          id="connection-url"
          name="connection-url"
          :label="$t('view.settings.connection.input.label')"
          placeholder="http://10.0.0.1:8352"
          :value="connectionStore.connectionUrl"
          @input="onUrlInput"
        />
        <div
          v-show="showInvalidUrlError"
          class="text-red-600 dark:text-red-500"
        >
          {{ $t('view.settings.connection.input.error.invalid-url.label') }}
        </div>
        <ConnectionStatus class="mb-2" :state="connectionTestState" />
      </div>
    </fieldset>
  </div>
</template>
