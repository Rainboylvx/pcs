import lokijs from "lokijs";

//数据库的封装
export default class MyDb  {

    constructor(db_name="pcs.db") {
        this.db = new lokijs('example')
        this.articles = this.db.addCollection('articles',{indices:['_id']})
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
        this.articles.chain().where(({_id,title}) => {
        })
    }

    filter_by_tag(tagNames) {

    }
};

