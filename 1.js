import data from './json/info_headers.json' assert { type: "json" };
console.log(data.length)

console.log(data[0])
for( let d of data) {
    if( d._id == 'luogu-P3959')
        console.log(d)
}
