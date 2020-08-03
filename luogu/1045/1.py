def f(n,p):
    s = 1
    base = 2
    while p:
        if p & 1:
            s = s *base
        base = base *base
        p = p >>1
    return s

def cutText(text, sec):
    return [text[i:i+sec] for i in range(0,len(text),sec)]

p = int(input())
s = str(f(2,p)-1)
print(len(s))
if len(s) > 500 :
    s = s[:500]
else:
    s = '0'*(500-len(s)) + s
print( '\n'.join(cutText(s,50)))

