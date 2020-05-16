#!/usr/bin/env python
from cyaron import *

#=== 字符串
# s1 = String.random(5) # 生成一个5个字母的单词，从小写字母中随机选择
# s1 = String.random((10, 20), charset="abcd1234") # 生成一个10到20个字母之间的单词，从abcd1234共8个字符中随机选择
# s1 = String.random(10, charset="#######...") # 生成一个10个字母的只有'#'和'.'组成的字符串，'#'的可能性是70%，'.'可能30%。
# s1 = String.random_sentence((10, 20), word_separators=",;", sentence_terminators=None, first_letter_uppercase=False, word_length_range=(2, 10), charset="abcdefg") # 生成一个10到20个单词的句子，以逗号或分号随机分割，第一个单词首字母不大写，结尾没有任何符号，每个单词2到10字母长，从abcdefg共7个字符中随机选择
# 以上所有参数，对于以下所有指令也有效

print(1)
n = 5;
m = 5
w = 3
print(n,m,w)
graph = Graph.graph(n, m+w, self_loop=False, repeated_edges=False,weight_limit=10) # 生成一个n点，m边的无向图，禁止重边和自环
# print(' '.join(list([ str(x+1) for x in range(0,n)])))
for edge in graph.iterate_edges(): # 遍历所有边，其中edge内保存的也是Edge对象
    print(edge.start,edge.end,edge.weight)
    # edge.start # 获取这条边的起点
    # edge.end # 获取这条边的终点
    # edge.weight # 获取这条边的边权
    # io.input_writeln(edge) # 输出这条边，以u v w的形式
