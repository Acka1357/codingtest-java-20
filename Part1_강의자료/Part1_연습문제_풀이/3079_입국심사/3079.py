def how_many_pass(given_time, time_per_pass):
    count = 0
    for t in time_per_pass:
        count += given_time // t
    return count

N, M = map(int, input().split())

time_per_pass = [int(input()) for _ in range(N)]

ans = 0
l = 1
r = min(time_per_pass) * M

while l <= r:
    m = (l + r) // 2
    if how_many_pass(m, time_per_pass) >= M:
        ans = m
        r = m - 1
    else:
        l = m + 1

print(ans)
