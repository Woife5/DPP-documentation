<script setup lang="ts">
import TextInput from '@/components/ui/inputs/TextInput.vue'
import { useConnectionStore } from '@/stores/connection.store'

const connectionStore = useConnectionStore()

function onUrlInput(value: string) {
  connectionStore.connectionUrl = value
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

      <TextInput
        id="connection-url"
        name="connection-url"
        :label="$t('view.settings.connection.input.label')"
        placeholder="http://10.0.0.1:8352"
        :value="connectionStore.connectionUrl"
        @input="onUrlInput"
      />
    </fieldset>
  </div>
</template>
