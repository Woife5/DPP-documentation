<script setup lang="ts">
import TextInput from '@/components/ui/inputs/TextInput.vue'
import { useConnectionStore } from '@/stores/connection.store'
import TestConnectionButton, {
  type TestState,
} from './TestConnectionButton.vue'
import { besAirService } from '@/services/bes-air.service'
import { ref } from 'vue'

const connectionStore = useConnectionStore()

function onUrlInput(value: string) {
  connectionStore.connectionUrl = value
}

const testConnectionState = ref<TestState>('unset')

connectionStore.$subscribe(() => (testConnectionState.value = 'unset'))

async function testConnection() {
  testConnectionState.value = 'pending'
  try {
    await besAirService.getBesnState()
    testConnectionState.value = 'success'
  } catch (error) {
    testConnectionState.value = 'fail'
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
        <TestConnectionButton
          :state="testConnectionState"
          @click="testConnection"
        />
      </div>
    </fieldset>
  </div>
</template>
