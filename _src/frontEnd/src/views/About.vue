<template>
<div>
<markdown :md='readme.__content'></markdown>
</div>
</template>

<script lang="ts" setup>
import { ref } from 'vue'

import markdown from '@/components/markdown.vue'
//import readme from 'virtual-markdown-render:readme.md'
import readme from '../../../../json/readme.json'

</script>

<style></style>
