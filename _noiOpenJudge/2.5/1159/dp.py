# coding:utf-8

import os
cnt=1
while True:
    os.system('python 1.py >input')
    os.system('./1 < input >output.a')
    os.system('./2 < input >output.b')
    if os.system('diff output.a output.b') != 0:
        print("error ans !")
        exit(1)
    else:
        # print("test right {}".format(cnt))
        cnt = cnt+1
