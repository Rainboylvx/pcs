<script lang="ts" setup>
import {useRoute} from 'vue-router'
import {computed} from 'vue'
const route=useRoute();

const current_path = computed(() =>route.path)

import HomeLog from '../icon/home.svg?component'
import ListLog from '../icon/list.svg?component'
import TagLog from '../icon/tags.svg?component'
import BulbLog from '../icon/bulb.svg?component'

const active_class = "bg-gray-900 text-white px-3 py-2 rounded-md text-sm font-medium";
const no_active_class = "text-gray-300 hover:bg-gray-700 hover:text-white px-3 py-2 rounded-md text-sm font-medium";
const LINKS = [
    ['主页','/'],
    ['列表','/'],
    ['标签云','/tags'],
    ['题解集','/collection'],
    ['关于','/about'],
]
</script>

<template>
<!-- <nav> -->
<!-- <ul> -->
<!--     <li><router-link to="/"><HomeLog /></router-link></li> -->
<!--     <li><router-link to="/"><ListLog /></router-link></li> -->
<!--     <li><router-link to="/"><TagLog /></router-link></li> -->
<!--     <li><router-link to="/about"><BulbLog /></router-link></li> -->
<!-- </ul> -->
<!-- </nav> -->
<nav class="bg-gray-800 dark:bg-slate-800 border-b border-b-gray-700">
  <div class="mx-auto max-w-7xl px-2 sm:px-6 lg:px-8">
    <div class="relative flex h-16 items-center justify-between">

      <div class="flex flex-1 items-center justify-center sm:items-stretch sm:justify-start">
        <div class="flex flex-shrink-0 items-center">
          <img class="block h-8 w-auto lg:hidden" src="/static/favicon.ico" alt="PCS">
          <img class="hidden h-8 w-auto lg:block" src="/static/favicon.ico" alt="PCS">
        </div>
        <div class="hidden sm:ml-6 sm:block">
          <div class="flex space-x-4">
            <!-- Current: "bg-gray-900 text-white", Default: "text-gray-300 hover:bg-gray-700 hover:text-white" -->
            
            <router-link :to="link[1]" v-for="(link,idx) in LINKS" :key="idx" :class="current_path == link[1] ? active_class : no_active_class">
                {{link[0]}}
            </router-link>

          </div>
        </div>
      </div>

      <div class="absolute inset-y-0 right-0 flex items-center pr-2 sm:static sm:inset-auto sm:ml-6 sm:pr-0">
        <button type="button" class="rounded-full bg-gray-800 p-1 text-gray-400 hover:text-white focus:outline-none focus:ring-2 focus:ring-white focus:ring-offset-2 focus:ring-offset-gray-800">
          <span class="sr-only">View notifications</span>
          <!-- Heroicon name: outline/bell -->
          <svg class="h-6 w-6" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="1.5" stroke="currentColor" aria-hidden="true">
            <path stroke-linecap="round" stroke-linejoin="round" d="M14.857 17.082a23.848 23.848 0 005.454-1.31A8.967 8.967 0 0118 9.75v-.7V9A6 6 0 006 9v.75a8.967 8.967 0 01-2.312 6.022c1.733.64 3.56 1.085 5.455 1.31m5.714 0a24.255 24.255 0 01-5.714 0m5.714 0a3 3 0 11-5.714 0" />
          </svg>
        </button>

      </div>
    </div>
  </div>

  <!-- Mobile menu, show/hide based on menu state. -->
  <div class="sm:hidden" id="mobile-menu">
    <div class="space-y-1 px-2 pt-2 pb-3">
    </div>
  </div>
</nav>

</template>

<style lang="scss" scoped>

nav {
}

</style>
