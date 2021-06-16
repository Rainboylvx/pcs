const {execSync} = require("child_process")
const cheerio = require("cheerio")
const {checkPrime} = require("crypto")
const fs = require("fs")

/**
 *@method html
 *@param {参数类型} 参数名 参数说明
 *@return {返回值类型} 返回值说明
 *@desc 根据目标对象获取运营商
 */
var cookie = 'PHPSESSID=4ek7htni30j0kjj96pb7ndjgq3; SL_GWPT_Show_Hide_tmp=1; SL_wptGlobTipTmp=1; Hm_lvt_cba6845c6d8176f123f81538e1796b8a=1621767342,1622372539,1622977167; Hm_lpvt_cba6845c6d8176f123f81538e1796b8a=1623811084'
var charter = ''
function html(url) {
  console.log(`url: ${url}`)
  return execSync(`curl --cookie "${cookie}" ${url}`, {encoding: 'utf8'})
}

console.log("不要忘了修改本文件的cookie")
if (process.argv.length < 3) {
  console.log("输入 章节id，如：ch0205 -> http://noi.openjudge.cn/ch0205/")
  console.log("然后遍历下面的所有的文件")
  process.exit()
}

charter = process.argv[2]

var charter_html = html(`http://noi.openjudge.cn/${charter}`)
//console.log(charter_html)

var $ = cheerio.load(charter_html)

var problemsList = $('#problemsList > table > tbody > tr')
console.log(problemsList.length)


/**
 *@method get_accept_code_by_url
 *@param {参数类型} 参数名 参数说明
 *@return {返回值类型} 返回值说明
 *@desc 根据目标对象获取运营商
 */
function get_accept_code_by_url(problem_url, problem_name, problem_id) {
  let raw_html = html(`http://noi.openjudge.cn/${problem_url}`)
  let $ = cheerio.load(raw_html)
  let accept = $(`td.result > a.result-right`)
  console.log(accept.length)
  if (accept.length == 0) { //没有
    console.log('这个题目没有正确的提交')
    return;
  }
  let accept_url = accept.eq(0).attr('href')
  let code_html = html(accept_url)
  let code = cheerio.load(code_html)('.sh_cpp').text()
  console.log('----->')
  console.log(code)
  console.log('<-------')

  let md = `---
_id: noiOpenJudge-${charter}-${problem_id}
title: ${problem_id}:${problem_name}
date: 2019-08-09 12:13
update: 2019-08-09 12:13
author: Rainboy
---

\`\`\`c
<%- include("${problem_id}.cpp") %>
\`\`\`

`
  fs.writeFileSync(`${problem_id}.md`, md, {encoding: 'utf8'})

  fs.writeFileSync(`${problem_id}.cpp`, code, {encoding: 'utf8'})
}

problemsList.each(function () {
  let isSoled = $(this).find('td:nth-child(1)>img').length == 1
  let problem_id = $(this).find('td:nth-child(2)').text()
  let problem_url = $(this).find('td:nth-child(2)>a').attr('href')
  let problem_name = $(this).find('td:nth-child(3)').text()
  //console.log(isSoled, problem_id, problem_url, problem_name)
  get_accept_code_by_url(problem_url, problem_name, problem_id)

})

