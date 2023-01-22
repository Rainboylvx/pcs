<template>
article
<div>
    <div class="markdown-body" v-html="mainStore.article">
    </div>
</div>
</template>

<script lang="ts" setup>
import {useMainStore} from '../stores/main.store'
const mainStore = useMainStore()
    </script>
