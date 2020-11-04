const fs = require("fs")
var {execSync:e} = require("child_process")

var con = fs.readFileSync("./新手村.md",{encoding:"utf8"}).split('\n')


var getInfo = function(id){
  let realId = /^\d/.test(id) ? `P${id}` : id;

  let a = e(`curl -s https://www.luogu.com.cn/problem/${realId}`,{encoding:'utf-8'})
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
let pp = []
for( let p of con){
  if( /P(\d{4})/.test(p)){
    let num = p.match(/P(\d{4})/)[1]
    //console.log(num)
    let title =  getInfo(num).currentTitle 
    pp.push(`- [P${num} ${title}](/article/luogu-P${num})`)
  }
  else 
    pp.push(p)
}
console.log(pp.join('\n'))

