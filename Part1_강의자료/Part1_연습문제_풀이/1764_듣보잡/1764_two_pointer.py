import sys
input = sys.stdin.readline

N, M = map(int, input().split())
unhear = sorted([input().rstrip() for _ in range(N)])
unseen = sorted([input().rstrip() for _ in range(M)])

pair_idx = 0
ans = []
for x in unhear:
    while pair_idx < M and unseen[pair_idx] < x:
        pair_idx += 1
    if pair_idx < M and unseen[pair_idx] == x:
        ans.append(x)

print(len(ans))
for name in ans:
    print(name)
