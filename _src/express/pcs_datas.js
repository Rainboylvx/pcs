//搜索所有pcs的数据
import {get_all_md} from '../lib/utils.js'
import markdownClass from '../lib/markdown.js'
const markdown = new markdownClass();

class PCS_Datas {
    constructor() {
        //原始的头文件数据
        this.raw_info_headers = []
        let all_mds = get_all_md();
        for( let md_path of all_mds )
            this.raw_info_headers.push(markdown.only_get_yaml_header(md_path))
    }

    get_info_headers (){
        return this.raw_info_headers;
    }
};

const pcs_datas  = new PCS_Datas();

export default pcs_datas;

