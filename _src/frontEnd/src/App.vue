<template>
<myNav> </myNav>
hell
<router-view></router-view>

<router-link to="/">home </router-link>
<router-link to="/about">about</router-link>

</template>

<script lang="ts" setup>

import myNav from './components/nav.vue'
</script>
