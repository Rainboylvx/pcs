#!/usr/bin/env python
from cyaron import *

# for _ in range(1,10):
    # n = randint(3,6)
    # s1 = String.random(n, charset="[]()") # 生成一个10个字母的只有'#'和'.'组成的字符串，'#'的可能性是70%，'.'可能30%。
    # print(s1)

n = randint(3,6)
s1 = String.random(n, charset="[]()") # 生成一个10个字母的只有'#'和'.'组成的字符串，'#'的可能性是70%，'.'可能30%。
print(s1)
