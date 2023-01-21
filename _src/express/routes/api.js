import express   from 'express';
var router = express.Router();
import {jsonCache}   from "../cache.js"
import pcs_datas from '../pcs_datas.js';

/* GET users listing. */
router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});


//根据id返回对应的渲染后的markdown
router.get('/article/:_id',jsonCache(10),(req,res)=>{

})

router.get('/info_headers',(req,res)=>{
    return res.json(pcs_datas.get_info_headers())
})


// 根据

export default router;
