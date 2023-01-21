import { createApp } from 'vue'
import { createPinia } from 'pinia'

import App from './App.vue'
import router from './router'

/* Theme variables */
import './theme/variables.css'

const pinia = createPinia()
const app = createApp(App).use(router).use(pinia)

router.isReady().then(() => {
  app.mount('#app')
})
