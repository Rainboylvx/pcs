import { createApp } from 'vue'
import { createPinia } from 'pinia'

import '@/assets/github-markdown.css'
import '../../../node_modules/markdown-r/assets/markdown-r.scss'
import '../../../node_modules/markdown-r/assets/prism-theme/prism-tomorrow.css'


import App from './App.vue'
import router from './router'



/* Theme variables */
import './theme/variables.css'

import my_db from './loki_db'

const pinia = createPinia()
const app = createApp(App).use(router).use(pinia)

//https://cn.vuejs.org/api/application.html#app-provide
//https://cn.vuejs.org/guide/components/provide-inject.html
app.provide('my_db', my_db) //注册到

router.isReady().then(() => {
  app.mount('#app')
})
