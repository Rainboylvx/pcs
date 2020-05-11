const fs = require("fs")
var content = fs.readFileSync("./_YBTTG.md",{encoding:"utf-8"}).split("\n")

for(let i = 0 ;i< content.length;i++){
  let line = content[i]
  if( line.length == 0) continue;
  if( line.includes("/article")) continue
  if( line.includes("@@@")) continue
  if( line.includes("[题解]")) continue
  if( !/#\d{5}/.test(line)) continue
  let id = line.match(/#\d{5}/)[0].slice(1)
  if( fs.existsSync(`${id}/1.md`)){
    console.error(line)
    content[i] = `- [${line.replace("- ", "")}](@@@./${id}/1.md@@@)`
  }
}

console.log(content.join("\n"))

