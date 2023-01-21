//markdown 渲染
import MarkdownIt from "markdown-it";
//[javascript - How to resolve Node.js ES6 (ESM) Modules with the TypeScript Compiler (TSC). TSC doesn't emit the correct file-ext - Stack Overflow](https://stackoverflow.com/questions/44979976/how-to-resolve-node-js-es6-esm-modules-with-the-typescript-compiler-tsc-tsc)
import { readFileSync, writeFileSync } from 'fs';
import yamlFront from "yaml-front-matter";
import GrayMatter from 'gray-matter'
import * as Path from 'path'
import {pcs__dirname} from './utils.js'
import * as ejs from 'ejs';
import anchor from "markdown-it-anchor";
import kbdplugin from "markdown-it-kbd";
import attrs from "markdown-it-attrs";
import emoji from 'markdown-it-emoji';
import toc from "markdown-it-toc-done-right";
import mathjax3 from "markdown-it-mathjax3";
import crypto from 'crypto'


//封装成一个Markdown class

export default class _markdown {

    constructor(root_dir  = pcs__dirname,markdown_opts = {}) {
        this.root_dir = root_dir

        //构建 markdown
        this._md = MarkdownIt(Object.assign({ html: true, linkify: true }, markdown_opts));
        this._md.use(anchor, {})
            .use(attrs)
            .use(toc, { level: [2, 3] })
            .use(emoji)
            .use(kbdplugin)
            .use(mathjax3);
    }


    get_raw_orgin(md_file_path) {
        let real_path = md_file_path
        if(!Path.isAbsolute(md_file_path))
            real_path = Path.join(this.root_dir,md_file_path)
        return readFileSync(real_path, { encoding: 'utf8' })
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

        console.log('->',real_path )
        return ejs.render(
                readFileSync(real_path, { encoding: 'utf8' }),
                {}, // data TODO
                //options
                { filename: real_path}
        );
    }


    // 对给定的string 渲染出来带有yaml_header的md渲染后html数据
    md_render_with_yamlheader (md_text) {
        const yamlLoad = yamlFront.safeLoadFront(md_text);
        const md_html = this._md.render(yamlLoad.__content);
        return {
            ...yamlLoad,
            __content:md_html
        }
    };


    path_to_id(__path__) {
        return crypto.createHash('md5').update(__path__).digest('hex');
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
        let raw_md = ""
        try {
            raw_md = this.ejs_render(md_file_path)
        }
        catch(e){
            return {
                _id: this.path_to_id(md_file_path),
                title : Path.basename(md_file_path),
                error : `${e}`
            }
        }

        let header = GrayMatter(raw_md)
        if( header.isEmpty )
            header = {
                data:{ 
                    _id: this.path_to_id(md_file_path),
                    title : Path.basename(md_file_path)
                }
            }

        header.data.orign_path = md_file_path
        // todo
        return header.data
    }

    //对md文件路径进行 渲染,结果为
    //{
    //    [key:string] :any
    //    title:
    //    oj: {ojname,link}[]
    //    tags: string[]
    //    catalog: string
    //   __content: md_html
    //}
    __Render = (md_file_path) => {
        return md_render_with_yamlheader(ejs_render(md_file_path))
    }
};

