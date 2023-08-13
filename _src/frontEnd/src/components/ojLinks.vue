<template>
<div class="flex gap-x-1 items-center justify-center mb-4">
    <span class="dark:text-indigo-500">
        OnlineJudge :
    </span>
    <a v-for="(d,idx) in data || []" v-bind:key="`tag-${idx}`"
        class="text-white bg-blue-700 hover:bg-blue-800 focus:ring-4 focus:ring-blue-300 font-medium rounded-lg text-sm px-2 py-1 mr-2 mb-0 dark:bg-blue-600 dark:hover:bg-blue-700 focus:outline-none dark:focus:ring-blue-800"
        :href="d.url"
        target="__blank__"
    >

        {{d.oj}}
    </a>
</div>
</template>

<script>
export default {
  props: {
    data:Array
  }
}
</script>
