
//虚拟模块的前缀
//作用,调用此模块,得到相应的markdown的渲染后的数据
//[Plugin API | Vite](https://vitejs.dev/guide/api-plugin.html#virtual-modules-convention)
//-- 来自
//[Vite 虚拟模块不完全指北 - 掘金](https://juejin.cn/post/7128401663152357407)
//
// 使用 在相应的*.vue文件里 使用
// import renderdeMd from "virtual-markdown-renderdeMd:path/to/markdown.md";
import Path from 'path'
import File from 'fs'
import {pcs__dirname} from '../../lib/utils.js'
import markdown from '../../lib/markdown.js'

const modulePrefix = 'virtual-markdown-render:'
function check_id(id){
      const [, md_file_name] = id.split(modulePrefix)
      // 如果不符合则停止
      if (!md_file_name) return
      // if(Path.extname(md_file_name).toLowerCase() !== '.md') 
      //     return

      let real_path = md_file_name
      if( !Path.isAbsolute(real_path))
          real_path = Path.join(pcs__dirname,md_file_name)
      if( Path.extname(real_path).toLowerCase() != '.md')
          real_path += '.md'
      if( !File.existsSync(real_path))
          return
      return real_path
}

export default function MyVirtualMarkdownRenderPlugin() {
  // 虚拟模块的前缀，在使用的时候，模块名必须以这个作为前缀的模块名才会被进一步解析
  const virtualModuleId = 'virtual:MarkdownRender'
  const modulePrefix = 'virtual-markdown-render:'

  return {
    // 我们自定义的插件名
    name: 'my-virtual-blog-date-plugin',

    // import data from 'virtual-blog-data:_'
    //传递进来一个 就是 from 后面的名字 就是id
    resolveId(id :string) {
      // 判断是否符合插件的前缀条件
        let md_file_name = check_id(id)
        if( !md_file_name )
            return
        return id //正常
    },
    load(id:string) {
      // 在加载文件内容的钩子中返回这个虚拟模块的内容
      // const [, dir_] = id.split(modulePrefix)
      // 如果值不合法则跳过，加载下一个文件
      // if (!dir_) return
    let md_file_name = check_id(id)
    if(!md_file_name) return
      let MyMd = new markdown();
      // 返回一个预期的文件内容
      let _data = MyMd.md_render_with_yamlheader(md_file_name) //得到数据
      return `export default ${JSON.stringify(_data)}`
    }
  }
}
