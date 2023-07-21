const highlight = require("./lib/highlight.cjs")
const twemoji = require("twemoji")
const mdItContainer = require("markdown-it-container") 
const markdownItTocAndAnchor = require('markdown-it-toc-and-anchor').default;
const tm = require('markdown-it-texmath');
const pangu = require("pangu")

var MarkdownIt  = require("markdown-it")

MarkdownIt.prototype.render = function (src, env) {
  env = env || {};
  if( this.options.pangu)
    src = pangu.spacing(src)
  return this.renderer.render(this.parse(src, env), this.options, env);
};

var md = MarkdownIt({
    html:true,
    linkify:true,
    typographer:true,
    highlight:highlight
})


md.use( require("./lib/preWrapper.cjs"))
    .use( require("./lib/lineNumber.cjs"))
    .use(tm, { engine: require('katex'),
        delimiters: 'dollars',
        katexOptions: { macros: {"\\RR": "\\mathbb{R}"} } })
    .use( require("markdown-it-emoji") )
    // .use( require("markdown-it-multimd-table") ,{
    //           multiline:  true,
    //           rowspan:    false,
    //           headerless: true,
    // })
    .use( require("markdown-it-kbd") )
    .use( require("markdown-it-task-checkbox") )
    .use( mdItContainer ,... require("./lib/container/default.cjs"))
    .use( mdItContainer ,... require("./lib/container/fold.cjs"))
    .use( mdItContainer ,... require("./lib/container/class.cjs"))
    .use( mdItContainer ,... require("./lib/container/blackboard.cjs"))
    .use( require("./lib/viz-gallery.cjs"))
    //.use( require('./lib/bilibili_frame.js'))
    //.use( require('./lib/heading.js'))
    .use( require("markdown-it-imsize") )
    .use( require("markdown-it-ins-del") )
    .use( require("markdown-it-inline-comments") )
    .use( require("markdown-it-sup") )
    .use( require("markdown-it-sub") )
    .use( require("markdown-it-mark") )
    .use( require("markdown-it-abbr") )
    .use( require("markdown-it-footnote") )
    .use( markdownItTocAndAnchor ,{
        tocFirstLevel:2,
        tocLastLevel:3,
        //anchorLinkSymbol:'⇄'
    })
    .use( require('./lib/tocAnchorExtent.cjs'))

md.renderer.rules.emoji = function(token,idx){
    return twemoji.parse(token[idx].content)
}


module.exports = md
// export default md
