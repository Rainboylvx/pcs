<template>
<div>

<p> about</p>
{{ mainStore.count }}

<button @click="mainStore.increment"> add</button>
</div>
</template>

<script lang="ts" setup>
import { ref } from 'vue'

import { useMainStore } from '../stores/main.store'
const mainStore = useMainStore()
</script>

<style></style>
