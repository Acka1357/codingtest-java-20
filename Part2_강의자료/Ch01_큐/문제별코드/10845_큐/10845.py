import sys
input = sys.stdin.readline
from collections import deque

N = int(input())
queue = deque([])
for _ in range(N):
    command = input().split()

    if command[0] == "push":
        queue.append(int(command[1]))

    elif command[0] == "pop":
        print(queue.popleft() if queue else -1)

    elif command[0] == "size":
        print(len(queue))

    elif command[0] == "empty":
        print(0 if queue else 1)

    elif command[0] == "front":
        print(queue[0] if queue else -1)

    elif command[0] == "back":
        print(queue[-1] if queue else -1)
