<template>
<div class="flex flex-wrap gap-2 lg:w-[52rem] md:w-full mx-auto my-5">
    <template v-for="(count,tag,idx) in tag_clouds">
        <span class="relative
        bg-gray-100 p-2 rounded border cursor-pointer hover:border-gray-500 hover:shadow
        hover:bg-blue-100
        ">
            {{tag}}
            <label class="
            absolute
            -top-2
            -right-2
            bg-green-500 rounded-full p-1 text-xs">
                {{count}}
            </label>
        </span>
    </template>
</div>
</template>

<script lang="ts" setup>
import {onMounted} from 'vue'
import {tag_clouds} from 'virtual:blogData'

onMounted(()=>{
    console.log('onMounted -tag_clouds ',tag_clouds)
    })

</script>

