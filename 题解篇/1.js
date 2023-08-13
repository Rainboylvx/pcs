//const fs = require("fs")
import fs from "fs"
import {execSync} from 'child_process'
let cookie=""
let e = execSync

let raw = fs.readFileSync("./1.md",{encoding:'utf8'})


let raw1 = raw.split('\n')
var getInfo = function(id){
  let realId = /^\d/.test(id) ? `P${id}` : id;
    //console.log( 'realId',realId )

  // let a = e(`curl -H 'user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36' https://www.luogu.com.cn/problem/${realId}`,{encoding:'utf-8'})
  let a = e(`wget -O - https://www.luogu.com.cn/problem/${realId}`,{encoding:'utf-8'})
  let dataReg = /decodeURIComponent\("([\s\S]+?)"\)/
    if(!dataReg.test(a)) {
        // console.log(a)
        return "unknown"
        // return getInfo(id)
    }
  //console.log(a)
  //console.log(dataReg.test(a))
  //console.log( a.match(dataReg))
  let data_string = a.match(dataReg)[1]
  var data = JSON.parse(decodeURIComponent(data_string))
  //console.log(JSON.stringify(data,null,4))
  //console.log(data.currentData.lastCode)
  // return data
    return data.currentData.problem.title
}

function main(){
    // let a = getInfo(1255)
    // console.log(a)
    // return

    // const regx = /-\s*\[(P\d{4})\].*/
    const regx = /^(\d{4})$/
    for(let line of raw1) {
        
        if( regx.test(line))
        {
            let mat = line.match(regx)
            console.log( mat[1] )
            let data = getInfo(mat[1])
            // console.log(mat[1])
            console.log(`- [\`${mat[1]} ${data}\`](../luogu/${mat[1]}/1.md)`)

        }
        else
            console.log(line)
    }

}

main()
