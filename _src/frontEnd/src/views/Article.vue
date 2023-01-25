<template>
<div class="flex flex-col items-center">
    <h3 class="text-center text-2xl py-5">
        {{mainStore.info_header.title}}
    </h3>
    <Tag :tags="mainStore.info_header.tags || []" />

    <div>
    </div>
    <div class="lg:w-[52rem] md:w-full mx-auto markdown-body" v-html="mainStore.article">
    </div>
</div>
</template>

<script lang="ts" setup>
import {useMainStore} from '../stores/main.store'
import Tag from '@/components/tag.vue'

const mainStore = useMainStore()
    </script>
