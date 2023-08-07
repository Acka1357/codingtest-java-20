N = int(input())
q = [list(map(int, input().split())) for _ in range(N)]

ans = 0
for x in range(1, 10):
    for y in range(1, 10):
        for z in range(1, 10):
            if x == y or y == z or x == z:
                continue
            psb = True
            for i in range(N):
                qx = q[i][0] // 100
                qy = (q[i][0] // 10) % 10
                qz = q[i][0] % 10
                
                strike, ball = 0, 0
                if x == qx:
                    strike += 1
                elif x == qy or x == qz:
                    ball += 1
                if y == qy:
                    strike += 1
                elif y == qx or y == qz:
                    ball += 1
                if z == qz:
                    strike += 1
                elif z == qx or z == qy:
                    ball += 1
                if strike != q[i][1] or ball != q[i][2]:
                    psb = False
                    break
            if psb:
                ans += 1

print(ans)
