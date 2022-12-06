<script setup lang="ts"></script>

<template>
  <button
    class="bg-cyan-500 hover:bg-cyan-600 dark:bg-cyan-700 dark:hover:bg-cyan-600"
    type="button"
  >
    <slot>Click</slot>
  </button>
</template>

<style scoped>
@import './button.base.css';
</style>
