import { createRouter, createWebHistory } from 'vue-router'
import HomeView from './views/home-view/HomeView.vue'
import SettingsView from './views/settings-view/SettingsView.vue'
import AlarmView from './views/alarm-view/AlarmView.vue'

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/',
      name: 'home',
      component: HomeView,
    },
    {
      path: '/settings',
      name: 'settings',
      component: SettingsView,
    },
    {
      path: '/alarm',
      name: 'alarm',
      component: AlarmView,
    },
  ],
})

export default router
