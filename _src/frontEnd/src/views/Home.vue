<template>
<div class="home-container">
    <div class="search_container items-center justify-content-center">
        <div class="search_box">
            <div class="search_input">
                <input type="text" v-model="search_string" @input="search"/>
            </div>
            <button @click="search"> <SearchLog/> </button>
        </div>
        <div v-show="search_string && search_string.length">
            <h3> 搜索结果 </h3>
            <searchResultList :dataList="search_list" />
        </div>
        <div v-show="!search_string || search_string.length == 0" class="my-3">
            <h3 class="dark:text-gray-100"> 最新更新 </h3>
            <searchResultList :dataList="last_blog_data " />
        </div>
        <div>
            <button @click="get_more" class="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded">
                加载更多
            </button>
        </div>
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
const last_data_size = ref(5)
//const last_blog_data = info_headers.slice(0,last_data_size).map( d => {return {item:d} });
const last_blog_data = computed(
  () => {
        //return info_headers.slice(0,last_data_size.value).map(d => return {items:d});
let datas = info_headers.slice(0,last_data_size.value)
        let d2 = datas.map( d => { return {item:d}})
        return d2
        //return last_data_size.value;
    
  }
)


const search_string = ref(null)
const my_db = inject('my_db')

const search = debounce( ()=>{
    //console.log(search_string.value)
    //my_db.fzf_find();
    search_list.value =  data_fuzzy_search(search_string.value)
})

const get_more = function () {
    if( last_data_size.value + 5 <= info_headers.length)
        last_data_size.value +=5;
    else
        last_data_size.value = info_headers.length
}

</script>

<style lang="scss" scoped>

.home-container {
    display: grid;
    place-items: center;
}
@import '../style/search_bar.scss'
</style>
