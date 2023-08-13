#!/bin/env node
const fs = require("fs")
const Path = require('path')
var {execSync:e} = require("child_process")
const ejs = require("ejs")
let src  = fs.readFileSync(__dirname+"/nodelib/pcs.ejs",{encoding:'utf-8'})
var template = ejs.compile(src)

let id = process.argv.slice(2)
let oj = ''
if( id.length == 0 ){

    //得到录有的目录
    let cwd = process.cwd();
    // console.log( cwd )
    let BaseName = Path.basename(cwd)
    id = BaseName
    oj = Path.basename(Path.join(cwd,'..'))
    // console.log(oj)
}

const vjude_url_mirror = 'https://vjudge.csgrandeur.cn'
const getTitle= function(oj_id){
    let a = e(`wget -O - ${vjude_url_mirror}/problem/${oj_id}`,{encoding:'utf-8'})
    const titleReg = /<title>(.*)<\/title>/
    // console.log(a)
    let title = titleReg.exec(a)[1]
    return title.substring(0,title.lastIndexOf('-'));
}

// console.log(`download code :`)
console.log(oj,id)
const real_id = `${oj}-${id}`
const title = getTitle(real_id)
console.log(title)


let tel = template({
    _id : `vjudge-${real_id}`,
    title,
    tags:[],
    oj_name :`vjudge-${real_id}`,
    oj_url : `https://vjudge.net/problem/${real_id}`
})

fs.writeFileSync(`1.md`,tel.trim(),{encoding:'utf-8'})


