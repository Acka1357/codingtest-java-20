T = int(input())

for _ in range(T):
    N, M = map(int, input().split())

    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    a.sort()
    b.sort()

    ans = 0
    bi = 0
    for i in range(N):
        while bi < M and b[bi] < a[i]:
            bi += 1
        ans += bi
    print(ans)
