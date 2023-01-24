<template>
<div class="home-container">
    <div class="search_container items-center justify-content-center">
        <div class="flex gap-2 mb-3">
            <router-link to="/" class="rounded-sm bg-gray-100 py-1 px-4 border hover:bg-gray-100 hover:border-gray-400 shadow" >标签云</router-link>
            <router-link to="/" class="rounded-sm bg-gray-100 py-1 px-4 border hover:bg-gray-100 hover:border-gray-400 shadow">题单</router-link>
            <router-link to="/" class="rounded-sm bg-gray-100 py-1 px-4 border hover:bg-gray-100 hover:border-gray-400 shadow">关于</router-link>
        </div>
        <div class="search_box">
            <div class="search_input">
                <input type="text" v-model="search_string" @input="search"/>
            </div>
            <button @click="search"> <SearchLog/> </button>
        </div>
        <div v-show="search_string && search_string.length">
            <searchResultList :dataList="search_list" />
        </div>
        <!-- <div v-show="!search_string || search_string.length == 0"> -->
            <searchResultList :dataList="last_blog_data" />
        <!-- </div> -->
    </div>
</div>
</template>

<script lang="ts" setup>
import { ref ,inject,computed} from 'vue';
import { useMainStore } from '../stores/main.store'
import {debounce} from '../utils'
import {data_fuzzy_search} from '../fuse_search'
import SearchLog from '../icon/search.svg'
const mainStore = useMainStore()

import info_headers from 'virtual:blogData';

//前10个元素

//components
import searchResultList from '../components/search_result_list.vue'

const search_list = ref([])

//最新的数据
const last_blog_data = info_headers.slice(0,5).map( d => {return {item:d} });


const search_string = ref(null)
const my_db = inject('my_db')

const search = debounce( ()=>{
    console.log(search_string.value)
    //my_db.fzf_find();
    search_list.value =  data_fuzzy_search(search_string.value)
})

</script>

<style lang="scss" scoped>

.home-container {
    min-height: 100vh;
    display: grid;
    place-items: center;
}
@import '../style/search_bar.scss'
</style>
