//[JavaScript 函数防抖的实现](https://www.freecodecamp.org/chinese/news/javascript-debounce-example/)
export function debounce(func:any, timeout = 300){
  let timer:any;
  return (...args) => {
    clearTimeout(timer);
    timer = setTimeout(() => { func.apply(this, args); }, timeout);
  };
}
