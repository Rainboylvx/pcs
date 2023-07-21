// markdown-it plugin for generating line numbers.
// It depends on preWrapper plugin.

const lineNumbers = (rawCode) => {
    const code = rawCode.slice(
        rawCode.indexOf('<code>'),
        rawCode.indexOf('</code>')
    )

    const lines = code.split('\n')
    const lineNumbersCode = [...Array(lines.length - 1)]
        .map((line, index) => `<span class="line-number">${index + 1}</span><br>`).join('')

    const lineNumbersWrapperCode =
        `<div class="line-numbers-wrapper">${lineNumbersCode}</div>`

    const finalCode = (rawCode.slice(0,rawCode.indexOf('<code>')) + lineNumbersWrapperCode + rawCode.slice(rawCode.indexOf('<code>')))
    //const finalCode = rawCode
        //.replace('<!--afterbegin-->', `${lineNumbersWrapperCode}<!--afterbegin-->`)
        .replace('extra-class', 'line-numbers-mode')

    return finalCode
}


module.exports = md => {
    const fence = md.renderer.rules.fence
    md.renderer.rules.fence =  (...args)=>{
        const [tokens, idx] = args
        const token = tokens[idx]
        const viz_reg = /^viz($|-\w+)/
        const rawCode = fence(...args)
        if(viz_reg.test(token.info.trim()))
            return rawCode
        return lineNumbers(rawCode)
    }
}
