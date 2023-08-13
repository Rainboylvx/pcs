const fs = require("fs")
const Path = require('path')
var {execSync:e} = require("child_process")
// const ejs = require("ejs")
// let src  = fs.readFileSync(__dirname+"/nodelib/luogu_template.ejs",{encoding:'utf-8'})
// var template = ejs.compile(src)

const vjude_url_mirror = 'https://vjudge.csgrandeur.cn'
const get_info = function(oj,pid) {
  let a = e(`wget -O - ${vjude_url_mirror}/problem/${oj}-${pid}`,{encoding:'utf-8'})
    return a
}

let x = get_info('USACO',1251)
console.log(x)
