import lokijs from "lokijs";
import Fuse from 'fuse.js'
import Path from 'path'

//数据库的封装
export default class MyDb  {

    constructor(db_name="pcs.db") {
        this.db_name = db_name
        this.db = new lokijs(this.db_name)
        this.articles = this.db.addCollection('articles',{indices:['_id']})
    }


    //重新 加入数据
    reload(md_info_headers) {
        this.articles.clear()
        this.articles.insert(md_info_headers)
    }
    
    insert(md_info_header) {
        this.articles.insert(md_info_header)
    }

    //清空数据库
    clear(){
    }

    //添加一条数据
    insert(article_object) {
        this.articles.insert(article_object)
    }


    //查找
    findOne_by_id(_id) {
        return this.articles.findOne({_id})
    }


    //fzf find
    fzf_find(str) {
        console.log( 
            this.articles.chain().data()
        )
    }

    filter_by_tag(tagNames) {

    }
};


