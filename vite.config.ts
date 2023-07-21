import { defineConfig } from 'vite'
import { resolve ,join} from 'path'
import vue from '@vitejs/plugin-vue'
import svgLoader from 'vite-svg-loader'
import MyVirtualBlogDataPlugin from './_src/frontEnd/src/virtualDataModule'
// import MyMarkdownRender from './_src/frontEnd/src/virtualMarkdownRender'

import info_headers from './_src/lib/info_headers.json'
const outDir = 'json'
// https://vitejs.dev/config/
export default defineConfig({
  plugins: [vue(),svgLoader(),MyVirtualBlogDataPlugin(info_headers),/*MyMarkdownRender()*/],
  root:resolve(__dirname, '_src/frontEnd'),
  resolve:{
    alias:{
      '@' : resolve(__dirname, './_src/frontEnd/src')
    },
  },
  build: {
      rollupOptions: {
          input: {
              main: resolve(__dirname, '_src/frontEnd/index.html'),
          }
      },
      outDir: resolve(__dirname,'dist')
  },
  server :{
      proxy : {
          //除 virtual-markdown-render 的所有字符
          '^((?!virtual-markdown-render).)*\.md' : {
              target: 'http://127.0.0.1:8080/',
              changeOrigin: true,
              rewrite: (path) => join(outDir,path.replace('.md', '.json')),
              //rewrite: (p:string) => join(outDir,p.replace('.md', '.json'))
              //rewrite: (p:string) => {return '1.json'}
          }
        // '*\.md$':
        //     {
        //       rewrite: (path) => join(outDir,path.replace('.md', '.json')),
        //     }
      }
  }
  // server : {
  //     open:'index.html'
  // }

})
