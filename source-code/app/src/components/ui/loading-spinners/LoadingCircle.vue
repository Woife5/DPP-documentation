<script setup lang="ts"></script>

<template>
  <span
    class="loader w-9 h-9 rounded-full inline-block border-[4px] border-white border-solid"
  ></span>
</template>

<style scoped>
.loader {
  border-bottom-color: transparent;
  animation: rotation 1s linear infinite;
}

@keyframes rotation {
  0% {
    transform: rotate(0deg);
  }
  100% {
    transform: rotate(360deg);
  }
}
</style>
