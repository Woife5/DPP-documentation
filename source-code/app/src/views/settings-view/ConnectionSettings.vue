<script setup lang="ts">
import TextInput from '@/components/ui/inputs/TextInput.vue'
import { useConnectionStore } from '@/stores/connection.store'
import TestConnectionButton, {
  type TestState,
} from './TestConnectionButton.vue'
import { besAirService } from '@/services/bes-air.service'
import { onMounted, ref } from 'vue'

const connectionStore = useConnectionStore()

const showInvalidUrlError = ref(false)
const connectionTest = ref<TestState>('unset')

connectionStore.$subscribe(() => (connectionTest.value = 'unset'))

onMounted(() => validateInput(connectionStore.connectionUrl))

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

async function testConnection() {
  if (connectionTest.value === 'pending') return
  connectionTest.value = 'pending'
  try {
    await besAirService.getBesnState()
    connectionTest.value = 'success'
  } catch (error) {
    connectionTest.value = 'fail'
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

      <div class="flex items-end gap-x-2">
        <TextInput
          class="grow"
          id="connection-url"
          name="connection-url"
          :label="$t('view.settings.connection.input.label')"
          placeholder="http://10.0.0.1:8352"
          :value="connectionStore.connectionUrl"
          @input="onUrlInput"
        />
        <TestConnectionButton :state="connectionTest" @click="testConnection" />
      </div>
      <div v-show="showInvalidUrlError" class="text-red-600 dark:text-red-500 flex flex-col">
        <div class="leading-tight mt-2">
          {{ $t('view.settings.connection.input.error.invalid-url.label') }}
        </div>
        <div class="leading-tight">
          {{ $t('view.settings.connection.input.error.invalid-url.pattern', {pattern:'<http(s)>://<url>'}) }}
        </div>
      </div>
    </fieldset>
  </div>
</template>
