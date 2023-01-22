import { defineStore } from 'pinia'
import { computed, ref, readonly } from 'vue'

export const useMainStore = defineStore('main', () => {
  const count = ref(0)
  const loading = ref(false)

  function show_loading() { loading.value = true; }
  function hide_loading() { loading.value = false; }

  function increment() {
    count.value++
  }
  function decrement() {
    count.value--
  }

  const title = computed(() => `${count.value * 2}`)

  return {
    loading:readonly(loading),
    show_loading,hide_loading,

    count: readonly(count),
    title,
    increment,
    decrement,

  }
})
