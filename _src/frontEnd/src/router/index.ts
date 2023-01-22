import { createRouter, createWebHistory } from '@ionic/vue-router'
import { inject } from 'vue'
import { RouteRecordRaw } from 'vue-router'
import Home from '../views/Home.vue'
import About from '../views/About.vue'
import Article from '../views/Article.vue'
import {useMainStore} from '../stores/main.store'
import { get_artilce } from '../axios'

import my_db from '../loki_db'
import {header} from 'express/lib/request'

const routes: Array<RouteRecordRaw> = [
  {
    path: '/',
    redirect: '/home',
  },
  {
    path: '/home',
    component: Home,
  },
  {
    path:'/article/:id',
    component:Article,
    name:'Article'
  },
  {
    path: '/about',
    component: About,
  },
]

// https://vitejs.dev/guide/env-and-mode.html
const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes,
})

router.beforeEach( (to,from)=> {
    console.log(to)
    if(to.name === 'Article') {
        let article_info = my_db.findOne_by_id(to.params.id)
        console.log( article_info )
        console.log( article_info.orign_path )
        get_artilce(article_info.orign_path).then( ({header,__content})=>{
            const mainStore = useMainStore()
            mainStore.set_article(__content)
            mainStore.set_info_header(header)
        })

        return true;
    }
    return true;

})

export default router
