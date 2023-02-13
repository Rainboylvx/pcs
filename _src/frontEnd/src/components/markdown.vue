<template>
    <h3 class="text-center text-2xl py-5 dark:text-gray-400">
        {{props.header.title || '未知'}}
    </h3>
    <Tag :tags="header.tags || []" />

    <div>
    </div>
    <div class="lg:w-[52rem] md:w-full mx-auto markdown-body" v-html="md">
    </div>
</template>

<script lang="ts" setup>
const props = defineProps({
        header:{
                type:Object,
                required:true,
                default:{}
        },
        md:String
    })
</script>
