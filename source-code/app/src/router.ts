import { createRouter, createWebHistory } from 'vue-router'
import HomeView from './views/home-view/HomeView.vue'
import SettingsView from './views/settings-view/SettingsView.vue'
import LEDView from './views/led-view/LEDView.vue'

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/',
      name: 'home',
      component: HomeView,
    },
    {
      path: '/about',
      name: 'about',
      // route level code-splitting
      // this generates a separate chunk (About.[hash].js) for this route
      // which is lazy-loaded when the route is visited.
      component: () => import('./views/about-view/AboutView.vue'),
    },
    {
      path: '/led-settings',
      name: 'led-settings',
      component: LEDView,
    },
    {
      path: '/settings',
      name: 'settings',
      component: SettingsView,
    },
  ],
})

export default router
