import os

cnt=0
for i in range(0,300):
    cnt+=1
    os.system("python3 1.py > in")
    os.system("./1 <in >out")
    print("succ %d" % cnt)


