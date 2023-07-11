K = int(input())

ans = str(bin(K + 1))[3:].replace('0', '4').replace('1', '7')

print(ans)
