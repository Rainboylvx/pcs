<template>
<div>
    <markdown :md='mainStore.article' :header="mainStore.info_header"></markdown>
</div>
</template>

<script lang="ts" setup>
import {useMainStore} from '../stores/main.store'
import markdown from '../components/markdown.vue'
import Tag from '@/components/tag.vue'

const mainStore = useMainStore()
    </script>
