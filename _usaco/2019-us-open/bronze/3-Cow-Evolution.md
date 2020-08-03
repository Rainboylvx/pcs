---
title: "3-Cow-Evllution"
level: 3
author: rainboy
create_time: 2019-07-03 16:05
update_time: 2019-07-03 16:05
tags:
    - usaco
    - 性质
source:
    - 
      oj: usaco
      url: http://usaco.org/index.php?page=viewproblem2&cpid=941
---

## 解析


这个题目的核心就在于**找出什么情况下不可能**!

当$[a,b],[a],[b]$时,不可能.

 - 第一头奶牛,有$a,b$
 - 第二头奶牛,有$a$
 - 第三头奶牛,有$b$

```plaintext
             1
            /
         a /
          / 
         2 
      b /
       / 
      3 
```





## 代码

```c
<%-include("3.cpp")%>
```

