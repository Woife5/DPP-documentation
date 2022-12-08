<script setup lang="ts">
import Header from './components/Header.vue'
import Main from './components/Main.vue'
import Footer from './components/Footer.vue'
import { initStores } from './stores/init-stores'

initStores()
</script>

<template>
  <Header />
  <Main />
  <Footer />
</template>
