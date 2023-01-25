//markdown 渲染
import  markdown  from "markdown-r";
//[javascript - How to resolve Node.js ES6 (ESM) Modules with the TypeScript Compiler (TSC). TSC doesn't emit the correct file-ext - Stack Overflow](https://stackoverflow.com/questions/44979976/how-to-resolve-node-js-es6-esm-modules-with-the-typescript-compiler-tsc-tsc)
import { readFileSync, writeFileSync } from 'fs';
import yamlFront from "yaml-front-matter";
import GrayMatter from 'gray-matter'
import * as Path from 'path'
import {pcs__dirname} from './utils.js'
import * as ejs from 'ejs';

import {ensureDirSync} from 'fs-extra'
import crypto from 'crypto'

//封装成一个Markdown class

export default class _markdown {

    constructor(ejs_data = {},root_dir  = pcs__dirname,markdown_opts = {}) {
        this.root_dir = root_dir
        this.ejs_data = ejs_data || {}

        //构建 markdown
        // this._md = MarkdownIt(Object.assign({ html: true, linkify: true }, markdown_opts));
        this._md = markdown

        // this._md.use((md)=> md.renderer.rules.link_open = this.link_open )
        this._md.renderer.rules.link_open = (...args) => this.link_open(...args);

    }


    get_raw_orgin(md_file_path) {
        let real_path = md_file_path
        if(!Path.isAbsolute(md_file_path))
            real_path = Path.join(this.root_dir,md_file_path)
        return readFileSync(real_path, { encoding: 'utf8' })
    }

    //得到真正的md文件的位置
    md_real_path(md_file_path) {
        return Path.resolve(pcs__dirname,decodeURI(md_file_path))
    }

    //得到原始的头文件
    get_raw_header (str) {
        let parsed = GrayMatter(str)
        if( parsed.isEmpty)
            return ""
        return parsed.matter
    }

    //对指定的md文件进行ejs渲染
    ejs_render(md_file_path) {

        let real_path = md_file_path
        if(!Path.isAbsolute(md_file_path))
            real_path = Path.join(this.root_dir,md_file_path)

        let raw = readFileSync(real_path, { encoding: 'utf8' })
        try {
            return ejs.render(
                raw,
                this.ejs_data, // data TODO
                //options
                { filename: real_path}
            );
        }
        catch(e) {
            console.error(e)
            return raw
        }
    }

    path_to_id(__path__) {
        return crypto.createHash('md5').update(__path__).digest('hex');
    }

    //

    //给一个md文件的路径,得到这个md文件的id
    get_md_id(md_path) {
        let id = this.only_get_yaml_header(md_path)._id ;
        if( id ) return id
        throw('can not get md file _id')
    }

    //预先 渲染
    __pre_render(md_file_path) {
        let raw_md = ""
        try {
            raw_md = this.ejs_render(md_file_path)
        }
        catch(e){ // ejs 渲染错误
            return {
                data:{
                    _id: this.path_to_id(md_file_path),
                    title : Path.basename(md_file_path),
                    orign_path:md_file_path
                },
                error : true,
                content: `${e}`
            }
        }

        let Matter = GrayMatter(raw_md)
        if( Matter.isEmpty ) // 没有yaml 头
            Matter = {
                data:{ 
                    title : Path.basename(md_file_path)
                }
            }

        if( !Matter.data._id) //没有_id
            Matter.data._id = this.path_to_id(md_file_path),

        Matter.data.path = md_file_path
        // console.log('->>', md_file_path)
        // console.log('->>', Matter.data.path )
        // todo
        let a = {
            content:Matter.content,
            data : {
                ...Matter.data,
                orign_path:md_file_path
            }
        }
        // console.log( a )
        return a;
    }

    //{
    //  _id: 'aoj-2843',
    //  title: '括号序列',
    //  date: '2020-04-30 13:46',
    //  update: '2020-04-30 13:46',
    //  author: 'Rainboy',
    //  tags: [ '递归', '2019安徽省程序设计竞赛' ],
    //  catalog: '递归',
    //  source: [
    //    { oj: 'AOJ', url: 'https://acm.webturing.com/problem.php?id=2843' }
    //  ],
    only_get_yaml_header = (md_file_path) =>{
        return this.__pre_render(md_file_path).data
    }

    // 对给定的string 渲染出来带有yaml_header的md渲染后html数据
    md_render_with_yamlheader (md_file_path) {
        let Matter = this.__pre_render(md_file_path)
        // console.log( Matter.data )

        return {
            header: Matter.data,
            __content: Matter.error 
                ? Matter.content  
                : this._md.render(Matter.content,{filename: this.md_real_path(md_file_path) })
        }
    };

 
/** 
 * 把对应的md文件渲染到指定的目录下的json文件
 * src: 原md 文件路径
 * dst: 输出的json文件路径
* */
    render_to_json_file (src,dst='dist'){
        if( Path.extname(src).toLowerCase() !== '.md' )
            return

        dst = Path.join(dst,Path.dirname(src),Path.basename(src).replace('.md', '.json'))

        //1.保证路径的存在
        ensureDirSync(Path.dirname(dst))
        
        console.log('org->', src )
        console.log('_.', dst )
        // console.log('_.', Path.dirname(dst) )

        let md_html_with_yamlheader =  this.md_render_with_yamlheader(src)
        //2.写入
        writeFileSync(dst,JSON.stringify(md_html_with_yamlheader),{encoding:'utf8'})

    }


    ///>>>>>>>>>> md hook
    
    link_open (tokens,i,options,env,self)
    {
        let token = tokens[i]
        let href = undefined
        token.attrs.forEach( ([attr,val])=>{
            if( attr.toLowerCase() == 'href')
                href = val
        })

        // console.log( token )
        // console.log( self.renderer)
        // console.log( options )
        // console.log( env)
        //不是绝对路径
        if( href && Path.extname(href).toLowerCase() == '.md' && !Path.isAbsolute(href) ) {
            let real_path = Path.resolve(Path.dirname(env.filename),href)
            let id = this.get_md_id(decodeURI( real_path) )
            for( let j = 0 ;j< tokens[i].attrs.length ; j++)
            {
                if(tokens[i].attrs[j][0] == 'href'){
                    tokens[i].attrs[j][1] = `/article/${id}`
                    // console.log( tokens[i] )
                    break
                }
            }
            // console.log( tokens[i] )
        }

        return self.renderToken(tokens,i,options,env)
    }
};

