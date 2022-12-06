<script setup lang="ts"></script>

<template>
  <header class="flex items-center mt-6">
    <div class="w-2/12 flex justify-center"></div>
    <div class="w-8/12 flex justify-center">
      <RouterLink :to="{ name: 'home' }">
        <h1 class="text-4xl">Bes Air App</h1>
      </RouterLink>
    </div>
    <div class="w-2/12 flex justify-center">
      <RouterLink :to="{ name: 'settings' }">
        <span class="text-2xl flex">
          <i class="material-icons">settings</i>
        </span>
      </RouterLink>
    </div>
  </header>
</template>
