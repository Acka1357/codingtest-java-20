N = int(input())
M = int(input())
broken = [] if M == 0 else list(map(int,input().split()))
is_broken = [1 if i in broken else 0 for i in range(10)]

def can_make_num(x):
    if x == 0:
        return not(is_broken[0])
    while x > 0:
        if is_broken[x % 10]:
            return 0
        x //= 10
    return 1
        

ans = N - 100 if N > 100 else 100 - N
for delta in range(ans):
    num_to_make = [N + delta, N - delta]
    for num in num_to_make:
        if num >= 0 and can_make_num(num):
            ans = min(ans, len(str(num)) + delta)

print(ans)
