//搜索所有pcs的数据
import {get_all_md} from '../lib/utils.js'
import markdownClass from '../lib/markdown.js'
import MyDb from '../lib/db.js'

const markdown = new markdownClass();
const myDb = new MyDb();


class PCS_Datas {
    constructor() {
        //原始的头文件数据
        this.raw_info_headers = []
        let all_mds = get_all_md();
        for( let md_path of all_mds ) {
            let header = markdown.only_get_yaml_header(md_path)
            this.raw_info_headers.push(header)
            try {
                myDb.insert(header)
            }
            catch(e){
                console.error(header)
                throw e
            }

        }

        // myDb.reload(this.raw_info_headers)
    }

    get_info_headers (){
        return this.raw_info_headers;
    }
};

const pcs_datas  = new PCS_Datas();

export default pcs_datas;

