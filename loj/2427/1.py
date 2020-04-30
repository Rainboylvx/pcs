a = []
try:
    while 1:
        b = input()
        t = list(b)
        t.sort()
        print("".join(t))
        a.append("".join(t))
        if b == '':
            break
except EOFError:
    print(list(set(a)))
    pass
