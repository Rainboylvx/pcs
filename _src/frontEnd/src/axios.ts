//[十分钟封装一个好用的axios，省时又省力他不香吗 - 掘金](https://juejin.cn/post/7090889657721815076)
import axios, { AxiosInstance, AxiosRequestConfig } from "axios";
import { useMainStore } from './stores/main.store'


const addLoading = () => useMainStore().show_loading()
const cancelLoading = () => useMainStore().hide_loading()




//根据配置创建一个axios的实例
export const createAxiosByinterceptors = (
  config?: AxiosRequestConfig
): AxiosInstance => {
  const instance = axios.create({
    timeout: 3000,    //超时时间
    baseURL:'/',
    //withCredentials: true,  //跨域携带cookie
    ...config,   // 自定义配置覆盖基本配置
  });

    // const mainStore = useMainStore()
// 添加请求拦截器
  instance.interceptors.request.use(
    function (config: any) {
      // 在发送请求之前做些什么
      console.log("config:", config);
      // config.headers.Authorization = vm.$Cookies.get("vue_admin_token");

        const { loading = true } = config;
        if( loading ) addLoading()
      return config;
    },
    function (error) {
      // 对请求错误做些什么
      return Promise.reject(error);
    }
  );

  // 添加响应拦截器
  instance.interceptors.response.use(
    function (response) {
        const { loading = true } = <any>response.config;
        if( loading) cancelLoading()

      // 对响应数据做点什么
      console.log("response:", response);
      return response.data
      const { status : code, data, message } = response.data;
      if (code === 200) return data;
      else if (code === 401) {
         //jumpLogin();
      } else {
         //Message.error(message);
         return Promise.reject(response.data);
      }
    },
    function (error) {
      // 对响应错误做点什么
      console.log("error-response:", error.response);
      console.log("error-config:", error.config);
      console.log("error-request:", error.request);
      if (error.response) {
        if (error.response.status === 401) {
          //jumpLogin();
        }
      }
      //Message.error(error?.response?.data?.message || "服务端异常");
      return Promise.reject(error);
    }
  );

  return instance;
};

export const Load = () =>{ 
    console.log( '123' )
    // const mainStore = useMainStore()
    // mainStore.show_loading()
}

const axios_inst = createAxiosByinterceptors();


///>>>>>>>> API

export const get_artilce = (md_path) =>{
    return axios_inst.get(md_path)
}
