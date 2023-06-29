t = int(input())

for i in range(t):
    n = int(input())
    s = ""
    for _ in range(n):
        s+=input()
    s = sorted(s)
    b = True
    for c in set(s):
        if(s.count(c)%n !=0):
            b=False
            break
    if(b):
        print("YES")
    else:
        print("NO")
