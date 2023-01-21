<template>
<div>
<p> home</p>
{{ mainStore.count }}

<button @click="mainStore.increment"> add</button>

</div>
</template>

<script lang="ts" setup>
import { useMainStore } from '../stores/main.store'
const mainStore = useMainStore()

</script>

<style>
.container {
  display: flex;
  justify-content: center;
  align-items: center;
}
</style>
