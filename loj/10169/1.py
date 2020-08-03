a = 0
for i in range(0,122):
    d = sum(map(lambda x : int(x=='1'),list(str(i))))
    # print("{} : {}".format( str(i),str(d)))
    a+=d
print(a)
a=0
for i in range(101,122):
    d = sum(map(lambda x : int(x=='1'),list(str(i))))
    # print("{} : {}".format( str(i),str(d)))
    a+=d
print(a)
