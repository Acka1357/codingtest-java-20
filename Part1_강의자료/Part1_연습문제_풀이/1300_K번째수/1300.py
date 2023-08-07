N = int(input())
K = int(input())

l = 1
r = N * N
ans = -1
while l <= r:
    m = (l + r) // 2
    count = 0
    for i in range(1, N+1):
        count += min(m // i, N)
    if count >= K:
        ans = m
        r = m - 1
    else:
        l = m + 1
print(ans)
