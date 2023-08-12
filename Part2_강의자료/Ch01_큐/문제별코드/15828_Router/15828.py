import sys
input = sys.stdin.readline
from collections import deque

N = int(input())
router = deque()
while True:
    cmd = int(input())
    if cmd > 0:
        if len(router) < N:
            router.append(cmd)
    elif cmd == 0 and router:
        router.popleft()
    else:
        break

if not router:
    print("empty")
else:
    print(*router)
