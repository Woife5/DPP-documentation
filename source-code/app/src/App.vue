<script setup lang="ts">
import Header from './components/Header.vue'
import Main from './components/Main.vue'
import Footer from './components/Footer.vue'
import { useLocaleStore } from './stores/locale.store'

useLocaleStore().initFromLocalStorage()
</script>

<template>
  <Header />
  <Main />
  <Footer />
</template>
