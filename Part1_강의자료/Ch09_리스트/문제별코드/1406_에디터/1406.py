import sys
input = sys.stdin.readline

origin = input().rstrip()
left_lst = list(origin)
right_lst = []
M = int(input())
while M > 0:
    cmd = input().rstrip()
    if cmd[0] == 'L':
        if left_lst:
            right_lst.append(left_lst.pop())
    elif cmd[0] == 'D':
        if right_lst:
            left_lst.append(right_lst.pop())
    elif cmd[0] == 'B':
        if left_lst:
            left_lst.pop()
    elif cmd[0] == 'P':
        left_lst.append(cmd[2])
    M -= 1

print(''.join(left_lst + right_lst[::-1]))
