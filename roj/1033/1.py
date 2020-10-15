import math
xa,ya,xb,yb = map(float,input().split())
ans = math.sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb))
print("%.3f" % ans)
