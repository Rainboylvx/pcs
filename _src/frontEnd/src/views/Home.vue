<template>
<div class="home-container">
    <div class="search_container">
        <div class="search_input">
            <input type="text" v-model="search_string"/>
        </div>
        <button @click="search"> <SearchLog/> </button>
    </div>
</div>
</template>

<script lang="ts" setup>
import { ref } from 'vue';
import { useMainStore } from '../stores/main.store'
import SearchLog from '../icon/search.svg'
const mainStore = useMainStore()

const search_string = ref(null)

const search = ()=>{
    console.log(search_string.value)
}

</script>

<style lang="scss" scoped>
@import '../style/search_bar.scss'
</style>
