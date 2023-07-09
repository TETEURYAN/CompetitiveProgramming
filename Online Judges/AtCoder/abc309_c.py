    N, K = map(int, input().split())
    ABs = [tuple(map(int, input().split())) for _ in range(N)]
     
    ABs.sort(key=lambda t: t[0], reverse=True)
    cur = 0
    day = 0
    for A, B in ABs:
        cur += B
        if cur > K:
            day = A
            break
     
    print(day + 1)
