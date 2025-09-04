import sys

input = sys.stdin.readline

left = list(input().strip()) #strip을 넣어야 줄바꿈을 없앰
right = []

m = int(input())
for _ in range(m):
    cmd = list(input().split())
    if cmd[0] == 'L' :
        if not left :continue
        tmp = left.pop()    
        right.append(tmp)
    if cmd[0] == 'D' :
        if not right : continue
        tmp = right.pop()
        left.append(tmp)
    if cmd[0] == 'B':
        if not left : continue
        left.pop()
    if cmd[0] == 'P':
        left.append(cmd[1])
print(''.join(left) + ''.join(reversed(right)))
