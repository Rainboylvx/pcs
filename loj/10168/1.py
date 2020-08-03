l=[112,113,114,122,123,124]
a = sum(map(lambda x:x*x,l))
print(a)
l2=[2,3,4]
l3=[12,13,14,22,23,24]
b1 = 3*pow(10,2)+2*10*(2+3+4)+( sum(map(lambda x:x*x,l2)))
b2 = 3*pow(20,2)+2*20*(2+3+4)+( sum(map(lambda x:x*x,l2)))
print(b1+b2)
x = sum(map(lambda x:x*x,l3))
print(x)
b3 = 6*pow(100,2)+2*100*(sum(l3))+b1+b2
print(b3)
