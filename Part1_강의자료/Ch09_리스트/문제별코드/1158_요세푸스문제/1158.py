N, K = map(int, input().split())
li = [i for i in range(1, N + 1)]
ans = []

past_idx = 0
for i in range(N):
    target_idx = (past_idx + K - 1) % len(li)
    ans.append(li.pop(target_idx))
    past_idx = target_idx

print('<' + ', '.join(map(str, ans)) + '>')
