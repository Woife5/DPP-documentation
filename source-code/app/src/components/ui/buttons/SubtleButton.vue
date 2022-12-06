<script setup lang="ts"></script>

<template>
  <button class="dark:hover:bg-slate-500" type="button">
    <slot>Click</slot>
  </button>
</template>

<style scoped>
@import './button.base.css';
</style>
