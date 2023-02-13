import { createRouter, createWebHistory } from '@ionic/vue-router'
import { inject } from 'vue'
import { RouteRecordRaw } from 'vue-router'
import Home from '../views/Home.vue'
import About from '../views/About.vue'
import Article from '../views/Article.vue'
import Collection from '@/views/collection.vue'
import tagCloud from '@/views/tag_cloud.vue'

import {useMainStore} from '../stores/main.store'
import { get_artilce } from '../axios'


import my_db from '../loki_db'
import {header} from 'express/lib/request'

const routes: Array<RouteRecordRaw> = [
  {
    path: '/',
    component: Home,
  },
  {
    path:'/article/:id',
    component:Article,
    name:'Article'
  },
  {
    path:'/collection/',
    component:Collection,
    name:'Collection'
  },
  {
    path:'/tags/',
    component:tagCloud,
    name:'Tags'
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
    // if( to.fullPath.indexOf('#') !== -1) {
    //     if ( to.fullPath.split('#')[0] == from.fullPath.split('#')[0]) {
    //         return false
    //     }
    // }
    console.log( from )
    console.log( to )
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
