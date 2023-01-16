<script setup lang="ts">
import { ref } from 'vue'

withDefaults(
  defineProps<{
    closable?: boolean
  }>(),
  {
    closable: true,
  }
)

const emits = defineEmits<{
  (e: 'close'): void
}>()

const dialogEl = ref<HTMLDialogElement>()

function open(): void {
  dialogEl.value?.showModal()
}

function close() {
  dialogEl.value?.close()
}

function onCloseClick(_e: Event) {
  close()
  emits('close')
}

defineExpose({
  open,
  close,
})
</script>

<template>
  <dialog
    ref="dialogEl"
    class="w-full bg-transparent p-0 backdrop:bg-light-dialog-backdrop backdrop:backdrop-blur-sm dark:backdrop:bg-dark-dialog-backdrop md:w-2/3 lg:w-1/2 2xl:w-1/3 md:h-1/3"
  >
    <form
      class="flex flex-col gap-y-2 rounded-sm bg-neutral-100 p-8 dark:bg-slate-800 dark:text-dark-normal"
      method="dialog"
    >
      <div class="flex items-center">
        <h1 class="flex-1">
          <slot name="header"></slot>
        </h1>

        <button
          v-if="closable"
          @click="onCloseClick"
          class="flex p-1 dark:bg-slate-700 dark:hover:bg-slate-600 rounded-sm"
        >
          <i class="material-icons">close</i>
        </button>
      </div>
      <slot></slot>
    </form>
  </dialog>
</template>
