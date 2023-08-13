#!/bin/env node
const fs = require("fs")
const Path = require('path')
var {execSync:e} = require("child_process")
const ejs = require("ejs")
let src  = fs.readFileSync(__dirname+"/nodelib/luogu_template.ejs",{encoding:'utf-8'})
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
  let realId = /^\d/.test(id) ? `P${id}` : id;
    console.log( 'realId',realId )

  // let a = e(`curl https://www.luogu.com.cn/problem/${realId} --cookie "${cookie}"`,{encoding:'utf-8'})
  let a = e(`wget -O - https://www.luogu.com.cn/problem/${realId}`,{encoding:'utf-8'})
  let dataReg = /decodeURIComponent\("([\s\S]+?)"\)/
  //console.log(a)
  //console.log(dataReg.test(a))
  //console.log( a.match(dataReg))
  let data_string = a.match(dataReg)[1]
  var data = JSON.parse(decodeURIComponent(data_string))
  //console.log(JSON.stringify(data,null,4))
  //console.log(data.currentData.lastCode)
  return data
}



f = id[0]
let info = getInfo(f)
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
let tel = template(info.currentData.problem)
fs.writeFileSync(`1.md`,tel.trim(),{encoding:'utf-8'})
