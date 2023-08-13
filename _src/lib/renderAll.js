// 功能: 渲染所的md文件为 json文件 并输出保存info_headers
import * as url from 'url';
import { get_all_md } from './utils.js'
import markdown from './markdown.js'
import {emptyDirSync} from 'fs-extra'
import {writeFileSync} from 'fs'
import {join,resolve} from 'path'


//渲染时需要的数据
const ejs_data  = {
    USER : {
        ROJ:'https://roj.ac.cn'
    }
}

//---> 搜索得到数据
const __dirname = url.fileURLToPath(new URL('.', import.meta.url));
const mymd = new markdown(ejs_data)

let mds = get_all_md()

let info_headers = []

const outDir = resolve( join(__dirname,'../../json'))
emptyDirSync(outDir)

let cnt = 0;
for( let md of mds) {

    // console.log( __Render(Path.join(pcs__dirname,md)) )
    // mymd.get_raw_header( mymd.get_raw_orgin(md) )

    //得到文件的头信息
    let info_header =  mymd.only_get_yaml_header(md)
    console.log(`${++cnt}:`, md,info_header._id) // 输出: 原始md路径

    //保存文件的头信息
    info_headers.push(info_header)

    //把这个md的路径,转换成json文件
    mymd.render_to_json_file(md,outDir)
}
    //能过时间来排序
info_headers.sort(({update: u1},{update: u2}) => u1 < u2 ? 1 : -1 )

//最后渲染一下readme.md
// mymd.render_to_json_file(resolve(join(__dirname,'../../readme.md')),outDir)
mymd.render_to_json_file('readme.md',outDir)
mymd.render_to_json_file('题解篇/_index.md',outDir)


//对info_headers进行排序
info_headers.sort( (a,b) => {
    let date_a = a.update ? new Date(a.update) : new Date()
    let date_b = b.update ? new Date(b.update) : new Date()
    return date_b < date_a
} )
writeFileSync(join(outDir,'info_headers.json'),JSON.stringify(info_headers),{encoding:'utf8'})
