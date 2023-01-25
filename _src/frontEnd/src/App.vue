<template>
<div class="p-5">
        <div class="flex gap-2 mb-3">
            <router-link to="/" class="rounded-sm bg-gray-100 py-1 px-4 border hover:bg-gray-100 hover:border-gray-400 shadow" >主页</router-link>
            <router-link to="/" class="rounded-sm bg-gray-100 py-1 px-4 border hover:bg-gray-100 hover:border-gray-400 shadow" >列表</router-link>
            <router-link to="/tags" class="rounded-sm bg-gray-100 py-1 px-4 border hover:bg-gray-100 hover:border-gray-400 shadow" >标签云</router-link>
            <router-link to="/collection" class="rounded-sm bg-gray-100 py-1 px-4 border hover:bg-gray-100 hover:border-gray-400 shadow">题解集</router-link>
            <router-link to="/about" class="rounded-sm bg-gray-100 py-1 px-4 border hover:bg-gray-100 hover:border-gray-400 shadow">关于</router-link>
        </div>
</div>
<loading v-model:active="mainStore.loading"
:can-cancel="false"
:is-full-page="true"/>

<!-- <myNav> </myNav> -->
<router-view></router-view>

<footer class="text-center">
        <p> copy by 
            <a href="https://github.com/rainboylvx" class="text-blue-500 hover:underline"> Rainboy .</a>
        </p>
</footer>
</template>

<script lang="ts" setup>
import { useMainStore } from './stores/main.store'
import {Load} from './axios'

import loading from 'vue-loading-overlay'
import 'vue-loading-overlay/dist/css/index.css';
import myNav from './components/nav.vue'


const mainStore = useMainStore()

</script>
