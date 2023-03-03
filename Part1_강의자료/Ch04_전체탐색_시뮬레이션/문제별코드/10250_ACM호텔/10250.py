for _ in range(int(input())):
	H, W, N = map(int, input().split())

	num = (N - 1) // H + 1
	floor = (N - 1) % H + 1
	print(floor * 100 + num)