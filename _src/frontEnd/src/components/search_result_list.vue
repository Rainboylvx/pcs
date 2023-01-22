<template>
<div class="search_result_list shadow rounded">
    <ul class="border mt-2 divide-y">
        <li v-for="({item},idx) in props.dataList" v-bind:key="idx">
            <div class="text-lg py-3">
                <router-link :to="`/article/${item._id}`" class="hover:text-blue-600">
                    {{item.title}}
                </router-link>
            </div>
            <div style="display:flex; justify-content: space-between; " class="text-sm">
                <div class="flex gap-x-1 items-center">
                    <tagLogo />
                    <span v-for="(tag,idx) in item.tags || []" v-bind:key="`tag-${idx}`"
                        class="bg-green-500 text-white p-1 rounded
                        cursor-pointer
                        "
                    >
                        {{tag}}
                    </span>
                </div>
                <div class="flex gap-x-1 items-center">
                    <linkLogo />
                    <a v-for="({oj,url},idx) in item.source || []" v-bind:key="`tag-${idx}`"
                        class="hover:underline decoration-1 text-blue-500
                        hover:text-blue-700
                        "
                        :href="url"
                        target="__blank"
                    >
                       {{oj}}
                    </a>
                </div>
            </div>
        </li>
    </ul>
</div>
</template>

<script lang="ts" setup>
import tagLogo from '../icon/tag.svg'
import linkLogo from '../icon/link.svg'

const props = defineProps({
        dataList:Array
    })


</script>

<style scoped lang="scss">

@import '../style/search_result_list.scss';

</style>
