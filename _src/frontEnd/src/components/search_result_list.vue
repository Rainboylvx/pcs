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
                <Tag :tags="item.tags" />
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
import linkLogo from '@/icon/link.svg'
import Tag from './tag.vue'

const props = defineProps({
        dataList:Array
    })


</script>

<style scoped lang="scss">

@import '../style/search_result_list.scss';

</style>
