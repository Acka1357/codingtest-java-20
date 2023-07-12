def howManyPass(givenTime, timePerPass):
    count = 0
    for t in timePerPass:
        count += givenTime // t
    return count

N, M = map(int, input().split())

timePerPass = [int(input()) for _ in range(N)]

ans = 0
l = 1
r = min(timePerPass) * M

while l <= r:
    m = (l + r) // 2
    if howManyPass(m, timePerPass) >= M:
        ans = m
        r = m - 1
    else:
        l = m + 1

print(ans)
