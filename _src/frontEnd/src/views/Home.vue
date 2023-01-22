<template>
<div class="home-container">
    <div class="search_container items-center justify-content-center">
        <div class="search_box">
            <div class="search_input">
                <input type="text" v-model="search_string" @input="search"/>
            </div>
            <button @click="search"> <SearchLog/> </button>
        </div>
        <searchResultList :dataList="search_list" />
    </div>
</div>
</template>

<script lang="ts" setup>
import { ref ,inject} from 'vue';
import { useMainStore } from '../stores/main.store'
import {debounce} from '../utils'
import {data_fuzzy_search} from '../fuse_search'
import SearchLog from '../icon/search.svg'
const mainStore = useMainStore()

//components
import searchResultList from '../components/search_result_list.vue'

const search_list = ref([])


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
