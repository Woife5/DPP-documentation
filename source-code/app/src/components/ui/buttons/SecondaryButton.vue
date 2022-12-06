<script setup lang="ts"></script>

<template>
  <button
    class="bg-slate-300 hover:bg-slate-400 dark:bg-slate-700 dark:hover:bg-slate-600"
    type="button"
  >
    <slot>Click</slot>
  </button>
</template>

<style scoped>
@import './button.base.css';
</style>
