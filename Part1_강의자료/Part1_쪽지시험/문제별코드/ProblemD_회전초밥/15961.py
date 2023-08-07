import sys
input = sys.stdin.readline

N, D, K, C = map(int, input().split())
dish = [int(input()) for _ in range(N)]
dish_count = [0] * (D + 1)
kind = 0

for i in range(K - 1):
    if dish_count[dish[i]] == 0:
        kind += 1
    dish_count[dish[i]] += 1

ans = 0
for i in range(N):
    if dish_count[dish[(i + K - 1) % N]] == 0:
        kind += 1
    dish_count[dish[(i + K - 1) % N]] += 1
    ans = max(ans, kind + (1 if dish_count[C] == 0 else 0))
    
    dish_count[dish[i]] -= 1
    if dish_count[dish[i]] == 0:
        kind -= 1

print(ans)
