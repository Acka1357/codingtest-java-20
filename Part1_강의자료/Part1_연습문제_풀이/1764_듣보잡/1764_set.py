import sys
input = sys.stdin.readline

N, M = map(int, input().split())
unhear = set(input().rstrip() for _ in range(N))

ans = []
for x in [input().rstrip() for _ in range(M)]:
    if x in unhear:
        ans.append(x)

ans.sort()
print(len(ans))
for name in ans:
    print(name)
