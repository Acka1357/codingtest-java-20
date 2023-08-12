import sys
input = sys.stdin.readline
from collections import deque

N = int(input())
q = deque()

for i in range(N):
    cmd = input().strip().split()
    if cmd[0] == "push_front":
        q.appendleft(int(cmd[1]))
    elif cmd[0] == "push_back":
        q.append(int(cmd[1]))
    elif cmd[0] == "pop_front":
        print(q.popleft() if q else -1)
    elif cmd[0] == "pop_back":
        print(q.pop() if q else -1)
    elif cmd[0] == "size":
        print(len(q))
    elif cmd[0] == "empty":
        print(1 if not q else 0)
    elif cmd[0] == "front":
        print(q[0] if q else -1)
    elif cmd[0] == "back":
        print(q[-1] if q else -1)
