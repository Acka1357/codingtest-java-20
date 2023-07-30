N = int(input())
cnt = [0]*10

while N > 0:
    cnt[N%10] += 1
    N //= 10

ans = (cnt[6] + cnt[9] + 1) // 2
for i in range(9):
    if i != 6:
        ans = max(ans, cnt[i])
    
print(ans)
