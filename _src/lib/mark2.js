import Md from './markdown.js'
import {isAbsolute,resolve,extname} from 'path'

const utils__filename = new URL('', import.meta.url).pathname;

// utils 
const myMd = new Md()

//修改渲染 link的方式



//let a = myMd._md.render('[h1](../../luogu/1000/P1000_超级玛丽游戏.md)',{filename:utils__filename})
let a = myMd.md_render_with_yamlheader('/home/rainboy/mycode/rbookr/pcs/luogu/1600/1.md')
console.log( a )
