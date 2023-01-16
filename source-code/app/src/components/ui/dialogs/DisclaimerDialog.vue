<script setup lang="ts">
import { ref } from 'vue'
import BasicDialog from '@/components/ui/dialogs/BasicDialog.vue'
import PrimaryButton from '@/components/ui/buttons/PrimaryButton.vue'

const dialog = ref<InstanceType<typeof BasicDialog>>()

function open() {
  dialog.value?.open()
}

function close() {
  dialog.value?.close()
}

defineExpose({
  open,
  close,
})
</script>

<template>
  <BasicDialog ref="dialog" :closable="false">
    <template v-slot:header>
      <div class="flex flex-wrap items-center justify-between">
        <span class="text-xl font-bold">
          {{ $t('app.cookie-disclaimer.heading') }}
        </span>
        <PrimaryButton @click="close">
          <div class="text-3xl p-2">
            {{ $t('app.cookie-disclaimer.button.accept.label') }}
          </div></PrimaryButton
        >
      </div>
    </template>
    <div class="flex flex-col items-end">
      <div>
        {{ $t('app.cookie-disclaimer.content') }}
      </div>
      <PrimaryButton @click="close">
        <div class="text-xs">
          {{ $t('app.cookie-disclaimer.button.decline.label') }}
        </div>
      </PrimaryButton>
    </div>
  </BasicDialog>
</template>
