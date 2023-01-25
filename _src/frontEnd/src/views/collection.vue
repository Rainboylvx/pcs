<template>
<markdown :header="md_collection.header" :md="md_collection.__content"> </markdown>
</template>

<script lang="ts" setup>
//import md_collection from 'virtual-markdown-render:_题解篇/_index.md'
import md_collection from 'virtual-markdown-render:_题解篇/_index.md'
import markdown from '@/components/markdown.vue'
</script>
