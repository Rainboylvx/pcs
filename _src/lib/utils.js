//一些常用的util 函数

import { dirname ,join} from "path";
import {fileURLToPath,URL} from 'url'
import glob from "glob";


// const src_dirname = dirname(fileURLToPath(import.meta.url))

const utils__filename = new URL('', import.meta.url).pathname;

// Will contain trailing slash
const src__dirname = new URL('.', import.meta.url).pathname;

//pcs的目录
export const pcs__dirname = join(src__dirname,'../..')

//所有符合条件的md文件
export const get_all_md = (dir = pcs__dirname)=>{

    //不以_开头的md文件
    return glob.sync("**/[^_]*.md",{
        cwd:dir,
        dot:true,
        nodir:true,
        ignore:['node_modules/**/*',
            'readme.md',
            '**/_*/**/*.md', //含有开头为_的目录
            ]
    })
}

