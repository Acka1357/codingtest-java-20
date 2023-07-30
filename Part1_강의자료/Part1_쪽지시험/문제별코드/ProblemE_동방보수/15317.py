def calc_need_amount(cost, budget, assign_cnt):
    need_amount = 0
    for i in range(assign_cnt):
        need_amount += max(cost[i] - budget[len(budget)-assign_cnt+i], 0)
    return need_amount

N, M, X = map(int, input().split())

cost = list(map(int, input().split()))
budget = list(map(int, input().split()))

cost.sort()
budget.sort()

l, r, ans = 0, min(N, M), 0
while l <= r:
    m = (l + r) // 2
    if calc_need_amount(cost, budget, m) <= X:
        ans = m
        l = m + 1
    else:
        r = m - 1

print(ans)
