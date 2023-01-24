<template>
<div class="flex gap-x-1 items-center">
    <tagLogo />
    <span v-for="(tag,idx) in tags || []" v-bind:key="`tag-${idx}`"
        class="bg-green-500 text-white p-1 rounded
        cursor-pointer
        "
    >
        {{tag}}
    </span>
</div>
</template>

<script>
import tagLogo from '@/icon/tag.svg'
export default {
    components:{tagLogo},
  props: {
    tags:Array
  }
}
</script>
