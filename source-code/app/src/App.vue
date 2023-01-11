<script setup lang="ts">
import Header from './components/Header.vue'
import Main from './components/Main.vue'
import Footer from './components/Footer.vue'
import DialogsContainer from './components/DialogsContainer.vue'
import { useLocaleStore } from './stores/locale.store'
import { useConnectionStore } from './stores/connection.store'
import { besAirService } from './services/bes-air-rest.service'

const localeStore = useLocaleStore()
localeStore.init()

const connectionStore = useConnectionStore()
besAirService.url = connectionStore.connectionUrl
connectionStore.$subscribe(
  (_mutation, state) => (besAirService.url = state.connectionUrl)
)
</script>

<template>
  <Header />
  <Main />
  <Footer />

  <DialogsContainer />
</template>
