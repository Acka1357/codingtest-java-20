def is_palindrome(num, B):
	lst = []
	while num > 0:
		lst.append(num % B)
		num //= B
	
	length = len(lst)

	for i in range(length >> 1):
		if lst[i] != lst[length - i - 1]:
			return 0
	return 1

for _ in range(int(input())):
	num = int(input())
	for B in range(2, 65):
		flag = is_palindrome(num, B)
		if flag == 1:
			break
	print(flag)