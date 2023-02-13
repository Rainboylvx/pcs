<template>
<div class="flex flex-col justify-between min-h-screen dark:bg-gray-800">
<loading v-model:active="mainStore.loading"
:can-cancel="false"
:is-full-page="true"/>

    <myNav> </myNav>
    <router-view></router-view>

    <footer class="text-center">
        <p class="dark:text-gray-400"> copy by <a href="https://github.com/rainboylvx" class="text-blue-500 hover:underline"> Rainboy .</a> </p>
    </footer>

</div>
</template>

<script lang="ts" setup>
import { useMainStore } from './stores/main.store'
import {Load} from './axios'

import loading from 'vue-loading-overlay'
import 'vue-loading-overlay/dist/css/index.css';
import myNav from './components/nav.vue'


const mainStore = useMainStore()

</script>
