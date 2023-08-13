#!/bin/env node
const fs = require("fs")
const Path = require('path')
var {execSync:e} = require("child_process")
const ejs = require("ejs")
let src  = fs.readFileSync(__dirname+"/nodelib/acw_template.ejs",{encoding:'utf-8'})
var template = ejs.compile(src)

let id = process.argv.slice(2)

if( id.length == 0 ){

    //得到录有的目录
  let cwd = process.cwd();
    console.log( cwd )
    let BaseName = Path.basename(cwd)
    id = [BaseName]

  // console.log(`usage: luogu_problem_lastCode pid1 pid2 ...`)
  // process.exit(-1)
}
console.log(`download code :`)
console.log(id)



let cookie = ''
var getInfo = function(id){
  let realId = parseInt(id) + 2
    console.log( 'realId',realId )

  // let a = e(`curl https://www.acwing.com/problem/content/description/${realId}/`,{encoding:'utf-8'})
  let a = e(`curl https://www.acwing.com/problem/content/${realId}/`,{encoding:'utf-8'})

    // console.log(a)
    let title_reg = /<title>(.*) - AcWing题库<\/title>/
    let title = a.match(title_reg)[1]
    // console.log( title )
    // <title>89. a^b - AcWing题库</title>
    //let keywords = "位运算,快速幂".replace('，', ',').split(',');
    let tags_reg = /let keywords = "(.*)"\.replace/
    let tags = a.match(tags_reg)[1].replace('，', ',').split(',')
    let data = {
        pid:id,
        title,
        tags
    }
  return data
}



f = id[0]
let info = getInfo(f)
console.log(info)

/*
console.log(info.currentData.problem.pid,info.currentData.problem.title)
console.log(info.currentData.problem)
//输出数据
console.log(`数据长度 : ${ info.currentData.problem.samples.length}`)
for( let i = 0 ;i < info.currentData.problem.samples.length || 0 ;i++){
  let name_in  =  i == 0 ? 'in' : `in${i+1}`
  let name_out  =  i == 0 ? 'rout' : `rout${i+1}`
  let [in_data,out_data] = info.currentData.problem.samples[i]
  fs.writeFileSync(name_in,in_data,{encoding:'utf-8'})
  fs.writeFileSync(name_out,out_data,{encoding:'utf-8'})
}
*/
let tel = template(info)
fs.writeFileSync(`1.md`,tel.trim(),{encoding:'utf-8'})
