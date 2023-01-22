<script lang="ts" setup>
import HomeLog from '../icon/home.svg?component'
import ListLog from '../icon/list.svg?component'
import TagLog from '../icon/tags.svg?component'
import BulbLog from '../icon/bulb.svg?component'
</script>

<template>
<nav>

<ul>
    <li><router-link to="/"><HomeLog /></router-link></li>
    <li><router-link to="/"><ListLog /></router-link></li>
    <li><router-link to="/"><TagLog /></router-link></li>
    <li><router-link to="/about"><BulbLog /></router-link></li>
</ul>

</nav>

</template>

<style lang="scss" scoped>

nav {
    position: fixed;
    right: 10rem;
    top:10rem;
    ul {
       list-style: none;
    }
}

</style>
