import os
import sys
for i in range(0,1000):
    os.system("python3 data.py > input")
    os.system("./t1 <input > 1.out")
    os.system("./t2 <input > 2.out")
    if os.system("diff -bB 1.out 2.out") == 0:
        print("yes %d" % i)
    else:
        print("no")
        sys.exit(1)

