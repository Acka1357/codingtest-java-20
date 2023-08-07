from collections import defaultdict

N = int(input())
acc = [[0] * (N + 1) for _ in range(N + 1)]

def get_sum(top, left, bottom, right):
    return acc[bottom][right] - acc[bottom][left - 1] - acc[top - 1][right] + acc[top - 1][left - 1]

for i in range(1, N + 1):
    row = list(map(int, input().split()))
    for j in range(1, N + 1):
        acc[i][j] = acc[i][j - 1] + acc[i - 1][j] - acc[i - 1][j - 1] + row[j - 1]

ans = 0
for r1 in range(1, N):
    for c1 in range(1, N):
        lt_vertex = defaultdict(int)
        lb_vertex = defaultdict(int)
        for r2 in range(1, r1 + 1):
            for c2 in range(1, c1 + 1):
                lt_vertex[get_sum(r2, c2, r1, c1)] += 1
            for c2 in range(c1 + 1, N + 1):
                lb_vertex[get_sum(r2, c1 + 1, r1, c2)] += 1
        
        for r2 in range(r1 + 1, N + 1):
            for c2 in range(1, c1 + 1):
                ans += lb_vertex[get_sum(r1 + 1, c2, r2, c1)]
            for c2 in range(c1 + 1, N + 1):
                ans += lt_vertex[get_sum(r1 + 1, c1 + 1, r2, c2)]

print(ans)
