import { defineConfig } from 'vite'
import { resolve ,join} from 'path'
import {URL} from 'url'
import vue from '@vitejs/plugin-vue'
import svgLoader from 'vite-svg-loader'
import * as url from 'url';
import MyVirtualBlogDataPlugin from './_src/frontEnd/src/virtualDataModule'
import { get_all_md } from './_src/lib/utils.js'
import markdown from './_src/lib/markdown.js'
import {emptyDirSync} from 'fs-extra'

import MyMarkdownRender from './_src/frontEnd/src/virtualMarkdownRender'

const ejs_data  = {
    USER : {
        ROJ:'https://roj.ac.cn'
    }
}

const __dirname = url.fileURLToPath(new URL('.', import.meta.url));
const mymd = new markdown(ejs_data)

let mds = get_all_md()

let info_headers = []

const outDir = 'dist'
emptyDirSync(outDir)

for( let md of mds) {
    // console.log( __Render(Path.join(pcs__dirname,md)) )
    // mymd.get_raw_header( mymd.get_raw_orgin(md) )
    let info_header =  mymd.only_get_yaml_header(md)
    info_headers.push(info_header)

    //把这个md的路径,转换成json文件
    mymd.render_to_json_file(md,outDir)
}

info_headers.sort(({update: u1},{update: u2}) => u1 < u2 ? 1 : -1 )


// https://vitejs.dev/config/
export default defineConfig({
  plugins: [vue(),svgLoader(),MyVirtualBlogDataPlugin(info_headers),MyMarkdownRender()],
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
      }
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
      }
  }
  // server : {
  //     open:'index.html'
  // }

})
