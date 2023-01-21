//cache middle
import mcache from "memory-cache"

//duration seconds
export const jsonCache = (duration ) =>  
    (req,res,next) =>{
        let key = '_express_' + req.originUrl  || req.url
        let cacheBody = mcache.get(key)
        if( cacheBody ){
            res.json(cacheBody)
            return;
        }
        else {
            res.jsonResponse = res.json
            res.json = (obj)=>{
                mcache.put(key,obj,duration*1000)
                res.jsonResponse(obj);
            }
            next()
        }
    }

