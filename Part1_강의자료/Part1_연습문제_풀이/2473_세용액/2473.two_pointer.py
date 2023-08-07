N = int(input())
arr = sorted(list(map(int,input().split())))
ans = arr[:3]
ans_abs = abs(sum(ans))

for i in range(N - 2):
    left_idx, right_idx = i + 1, N - 1
    while left_idx < right_idx:
        cur_sum = arr[i] + arr[left_idx] + arr[right_idx]
        cur_abs = abs(cur_sum)
        if ans_abs > cur_abs:
            ans = [arr[i], arr[left_idx], arr[right_idx]]
            ans_abs = cur_abs
        if cur_sum <= 0:
            left_idx += 1
        else:
            right_idx -= 1

print(' '.join(map(str, ans)))
