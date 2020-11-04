const fs = require("fs")
const pathFn = require("path")
const {execSync} = require("child_process")


let a = fs.readdirSync("./_题解篇/luogu新手村/")
for( let b of a){
  if(b[0] === 'P'){
    let num = b.slice(1).slice(0,4)
    //console.log(num)
    let res = execSync(`curl -s http://localhost:4046/utils/exists/luogu-P${num}`,{encoding:"utf8"})
    if(/false/.test(res)){
      console.log(num)
      //execSync(`rm -r luogu/${num}`)
      //execSync(`mkdir -p luogu/${num}/code`)
      //execSync(`mv ./_题解篇/luogu新手村/P${num}* luogu/${num}`)
      //execSync(`mv ./_题解篇/luogu新手村/code/${num}* luogu/${num}/code`)
    }
      //console.log(res)
    // exist
    //if( fs.existsSync("./luogu/"+num) ) {
      ////console.log(num,"have")
      //continue
    //}

    //console.log(num,"not have")
  }
}
