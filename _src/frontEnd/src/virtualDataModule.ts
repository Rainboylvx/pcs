
//虚拟模块的前缀
//作用,调用此模块,得到blog的扫描数据
//[Plugin API | Vite](https://vitejs.dev/guide/api-plugin.html#virtual-modules-convention)
//-- 来自
//[Vite 虚拟模块不完全指北 - 掘金](https://juejin.cn/post/7128401663152357407)

//得到所有的标签的数据与标签的数量
const tag_cloud = (_data:any[])=>{
    let cloud = {}
    for( let d of _data ){
        if(! d.tags ) continue
        for( let tag of d.tags ){
            if( !cloud[tag])
                cloud[tag] = 0
            cloud[tag]++;
        }
    }
    console.log( 'cloud->',cloud )
    return cloud
}


export default function MyVirtualBlogDataPlugin( _data:any[] ) {
  // 虚拟模块的前缀，在使用的时候，模块名必须以这个作为前缀的模块名才会被进一步解析
  const virtualModuleId = 'virtual:blogData'

  return {
    // 我们自定义的插件名
    name: 'my-virtual-blog-date-plugin',

    // import data from 'virtual-blog-data:_'
    //传递进来一个 就是 from 后面的名字 就是id
    resolveId(id :string) {
      // 判断是否符合插件的前缀条件
      // const [, dir_] = id.split(modulePrefix)
      // 如果不符合则停止
      // if (!dir_) return
      // 如果符合基本格式，但日期的值不合法，比如 13 月, 32 号
      // if (Number.isNaN(Date.parse(date))) {
      //   throw new Error('Trying to load an invalid date')
      // }
        // 一切正常则返回
      if( id === virtualModuleId)
          return id
      // 如果不符合则停止
    },
    load(id:string) {
        let _tags= tag_cloud(_data)
      // 在加载文件内容的钩子中返回这个虚拟模块的内容
      // const [, dir_] = id.split(modulePrefix)
      // 如果值不合法则跳过，加载下一个文件
      // if (!dir_) return
      if(id !== virtualModuleId)
          return
      // 返回一个预期的文件内容
      // let _data = Analyze(search_dir) //得到数据
      return `export default ${JSON.stringify(_data)}
export const tag_clouds = ${JSON.stringify(_tags)};
`
    }
  }
}
