<template>
    <h3 class="text-center text-2xl py-5 dark:text-gray-300 underline">
        {{props.header.title || '未知'}}
    </h3>
    <!-- oj的列表 -->
    <ojLinks :data="header.source || []" />
    <Tag :tags="header.tags || []" />

    <div class="lg:w-[52rem] md:w-full mx-auto markdown-body" v-html="md">
    </div>
</template>

<script lang="ts" setup>
import Tag from './tag.vue'
import ojLinks from './ojLinks.vue'
const props = defineProps({
        header:{
                type:Object,
                required:true,
                default:{}
        },
        md:String
    })
</script>

<style lang="scss">
</style>
