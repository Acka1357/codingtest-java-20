N = int(input())
alp_value = [0] * 26

for _ in range(N):
    word = input()
    place_value = 1
    for i in range(len(word)-1, -1, -1):
        alp_value[ord(word[i]) - ord('A')] += place_value
        place_value *= 10

alp_value = sorted(alp_value)

ans = 0
for i in range(10):
    ans += alp_value[25 - i] * (9 - i)

print(ans)
