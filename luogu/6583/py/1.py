a=[]
for i in range(1,101):
    t = i
    while t % 2 == 0:
        t /= 2
    while t % 5 == 0:
        t /= 5
    # print(t,i)
    a.append(str(int(t)))
print(" ".join(a))
