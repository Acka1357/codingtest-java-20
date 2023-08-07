N, M = map(int, input().split())
li = list(map(int, input().split()))

acc_remain_cnt = [0] * M
acc_remain_cnt[cur_remain := 0] = 1
ans = 0

for x in li:
    ans += acc_remain_cnt[cur_remain := (cur_remain + x) % M]
    acc_remain_cnt[cur_remain] += 1

print(ans)
