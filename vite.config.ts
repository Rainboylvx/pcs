import { defineConfig } from 'vite'
import { resolve } from 'path'
import {URL} from 'url'
import vue from '@vitejs/plugin-vue'
import svgLoader from 'vite-svg-loader'
import * as url from 'url';
const __dirname = url.fileURLToPath(new URL('.', import.meta.url));

//const __dirname = new URL('.',import.meta.url)

// https://vitejs.dev/config/
export default defineConfig({
  plugins: [vue(),svgLoader()],
  root:resolve(__dirname, '_src/frontEnd'),
  build: {
      rollupOptions: {
          input: {
              main: resolve(__dirname, '_src/frontEnd/index.html'),
          }
      }
  },
  // server : {
  //     open:'index.html'
  // }

})
