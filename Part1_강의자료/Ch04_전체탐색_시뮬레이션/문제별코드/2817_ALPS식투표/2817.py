X = int(input())
N = int(input())
staff = [tuple(input().split()) for _ in range(N)]
chip_cnt = {chr(i): 0 for i in range(65, 91)}
check = {chr(i): 0 for i in range(65, 91)}
v = []

for i in range(N):
    s, c = staff[i]
    c = int(c)
    if c * 20 >= X:
        check[s] = 1
        for j in range(1, 15):
            v.append((c / j, s))

v.sort(reverse=True)

for i in range(min(len(v), 14)):
    chip_cnt[v[i][1]] += 1

for i in range(65, 91):
    c = chr(i)
    if check[c]:
        print(c, chip_cnt[c])
