import { defineConfig } from 'vite'
import { resolve } from 'path'
import {URL} from 'url'
import vue from '@vitejs/plugin-vue'

//const __dirname = new URL('.',import.meta.url)

// https://vitejs.dev/config/
export default defineConfig({
  plugins: [vue()],
  root:'./_frontEnd',
  build: {
      rollupOptions: {
          input: {
              main: resolve(__dirname, '_frontEnd/index.html'),
          }
      }
  },
  server : {
      open:'/_frontEnd/index.html'
  }

})
