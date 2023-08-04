N, M = map(int, input().split())
arr = [input() for _ in range(N)]
res = [[0] * M for _ in range(N)]

for row in range(0, N):
    if arr[row][0] == '1':
        res[row][0] = 1

for col in range(0, M):
    if arr[0][col] == '1':
        res[0][col] == 1

for row in range(1, N):
    for col in range(1, M):
        if arr[row][col] == '1':
            res[row][col] = min(res[row - 1][col - 1], res[row - 1][col], res[row][col - 1]) + 1

print(max(map(max, res)) ** 2)
