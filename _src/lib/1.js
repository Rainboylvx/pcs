
import MD from './markdown.js'
import {get_all_md,pcs__dirname} from './utils.js'
import * as Path from 'path'

import Mydb from './db.js'

var mymd = new MD();

//创建一个db
var mydb = new Mydb();

let mds = get_all_md()

for( let md of mds) {
    // console.log( __Render(Path.join(pcs__dirname,md)) )
    // mymd.get_raw_header( mymd.get_raw_orgin(md) )
    let info_header =  mymd.only_get_yaml_header(md)
    console.log(info_header)
    mydb.insert(info_header)
    console.log( mydb.findOne_by_id(info_header._id) )
    break;
}
