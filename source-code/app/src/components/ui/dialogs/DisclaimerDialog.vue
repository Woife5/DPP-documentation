<script setup lang="ts">
import { ref } from 'vue'
import BasicDialog from '@/components/ui/dialogs/BasicDialog.vue'
import PrimaryButton from '@/components/ui/buttons/PrimaryButton.vue'

const props = defineProps<{
  headerTranslationKey: string
  contentTranslationKey: string
}>()

const emits = defineEmits<{
  (e: 'close'): void
  (e: 'accept'): void
}>()

const dialog = ref<InstanceType<typeof BasicDialog>>()

function open() {
  dialog.value?.open()
}

function close() {
  emits('close')
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
          <i18n-t tag="p" :keypath="props.headerTranslationKey">
            <template #newline><br /></template>
          </i18n-t>
        </span>
        <PrimaryButton
          @click="
            () => {
              emits('accept')
              close()
            }
          "
        >
          <div class="text-3xl p-2">
            {{ $t('app.cookie-disclaimer.button.accept.label') }}
          </div></PrimaryButton
        >
      </div>
    </template>
    <div class="flex flex-col items-end">
      <div>
        <i18n-t tag="p" :keypath="props.contentTranslationKey">
          <template #newline><br /></template>
        </i18n-t>
      </div>
      <PrimaryButton @click="close">
        <div class="text-xs">
          {{ $t('app.cookie-disclaimer.button.decline.label') }}
        </div>
      </PrimaryButton>
    </div>
  </BasicDialog>
</template>
