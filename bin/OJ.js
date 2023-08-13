#!/bin/env node
// https://juejin.im/post/6844903831097049096
/* 
 * Oj.js -n acwing -pid 1 -tag 
 * */
const fs = require("fs")
const commder = require("commander")
var {execSync:e} = require("child_process")
const ejs = require("ejs")
const commander = require("commander")
//let src  = fs.readFileSync(__dirname+"/nodelib/luogu_template.ejs",{encoding:'utf-8'})
//var template = ejs.compile(src)
let template_dict = {
  'acwing':{
    "pid_oj_name":"acwing",
    "pid_url":"https://www.acwing.com/problem/content/"
  },
  'roj':{
    "pid_oj_name":"roj",
    "pid_url":"<%- USER.ROJ %>problem/"
  }
}

commander
  .version('0.1.1')
  .option('-n, --ojname [oj-name]', 'oj-name')
  .option('-tt, --title [title]', '题目名字')
  .option('-t, --tag [tag1,tags2,...,tagn]', '标签')
  .option('-p, --pid [pid]', '题目id')
  .option('-c, --catalog [分类]', '分类')
  .parse(process.argv)

let {ojname,title,tag="",pid,catalog=null} = commander

function dateFormat(fmt, date) {
    let ret;
    let opt = {
        "Y+": date.getFullYear().toString(),        // 年
        "m+": (date.getMonth() + 1).toString(),     // 月
        "d+": date.getDate().toString(),            // 日
        "H+": date.getHours().toString(),           // 时
        "M+": date.getMinutes().toString(),         // 分
        "S+": date.getSeconds().toString()          // 秒
        // 有其他格式化字符需求可以继续添加，必须转化成字符串
    };
    for (let k in opt) {
        ret = new RegExp("(" + k + ")").exec(fmt);
        if (ret) {
            fmt = fmt.replace(ret[1], (ret[1].length == 1) ? (opt[k]) : (opt[k].padStart(ret[1].length, "0")))
        };
    };
    return fmt;
}
let ejs_template =`---
_id: "<%- pid_oj_name || ojname %>-<%- pid %>"
title: "<%- title %>"
date:  <%- _time %>
update:  <%- _time %>
author: Rainboy
<% if(tags){ %>
tags: <% for (let t of tags) {%>
 - <%- t%><%}%> <% } %>
<% if(catalog) {%>
catalog: <%- catalog %> <% } %>
source: 
    - 
      oj: <%- ojname %>
      url: <%- pid_url %><%- pid %>
---

@[toc]
## 解析


## 代码

\`\`\`c
<%%- include("1.cpp") %>
\`\`\`
`

if( !template_dict[commander.ojname] ){
  console.log(`没有这个OJ : ${commander.ojname}`)
  process.exit(1)
}


var template = ejs.compile(ejs_template)

//得到最后的参数

let argument = { ojname,title,pid,catalog }

if( tag.length !=0 )
  argument.tags = tag.split(",")
else
  argument.tags = null

argument._time = dateFormat("YYY-mm-dd HH:MM", new Date())

argument = {
  ...argument,
  ...template_dict[ojname]
}
console.error("======= 最终的参数为 ====")
console.error(JSON.stringify(argument,null,4))

var out = template(argument)

console.log(out)
