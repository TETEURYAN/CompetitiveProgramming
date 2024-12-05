n = int(input())
c = list(map(int, input().split()))

l = 0
r = n - 1
sp = 0
dp = 0

t = 1
while l <= r:
    if t == 1:
        sp += max(c[l], c[r])
        t = 0
    else:
        dp += max(c[l], c[r])
        t = 1
    if c[l] > c[r]:
        l += 1
    else:
        r -= 1

print(sp, dp)
