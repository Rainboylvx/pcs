import os
import sys

for i in range(0,1000):
    os.system("python3 data.py >in")
    if os.system("./t1 < in") != 0:
        print("no")
        sys.exit(1)
