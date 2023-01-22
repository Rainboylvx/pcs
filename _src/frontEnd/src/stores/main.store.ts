import { defineStore } from 'pinia'
import { computed, ref, readonly } from 'vue'

export const useMainStore = defineStore('main', () => {
  const count = ref(0)
  const loading = ref(false)

  //markdonw渲染后的东西
  const markdown_content = ref("")
  const info_header = ref({})

  function show_loading() { loading.value = true; }
  function hide_loading() { loading.value = false; }

  function increment() {
    count.value++
  }
  function decrement() {
    count.value--
  }

    function set_info_header( header:any) {
        info_header.value = header
    }
    
    function set_article(md:string){
        markdown_content.value = md
    }

  const title = computed(() => `${count.value * 2}`)

  return {
    loading:readonly(loading),
    show_loading,hide_loading,

    article:readonly(markdown_content),
    info_header:readonly(info_header),
    set_article,set_info_header,


    count: readonly(count),
    title,
    increment,
    decrement,

  }
})
