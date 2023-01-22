<template>
<loading v-model:active="mainStore.loading"
:can-cancel="false"
:is-full-page="true"/>

<myNav> </myNav>
<router-view></router-view>

{{mainStore.loading}}
{{mainStore.count}}
<button @click="xxx">
123
</button>
</template>

<script lang="ts" setup>
import { useMainStore } from './stores/main.store'
import {Load} from './axios'

import loading from 'vue-loading-overlay'
import 'vue-loading-overlay/dist/css/index.css';
import myNav from './components/nav.vue'


const mainStore = useMainStore()

const xxx = () =>{
    Load()
}
</script>
