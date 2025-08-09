from collections import deque

n = int(input())
k = int(input())

board = [[0]*n for _ in range(n)]
for _ in range(k):
    x,y = map(int, input().split())
    board[x-1][y-1] = 1
l = int(input())
commands = deque([tuple(input().split()) for _ in range(l)])

snake = deque([(0,0)]) 
directions = [(0,1), (1,0), (0,-1), (-1,0)]
direction = 0 # 0: right 1:down 2: left 3: up 
time = 0

while True:
    time +=1
    dx, dy = directions[direction]
    head_x, head_y = snake[0]
    new_head = (head_x+dx, head_y+dy)

    if not (0<= new_head[0] < n and 0 <= new_head[1] <n):
        break
    if new_head in snake :
        break
    if board[new_head[0]][new_head[1]] == 1:
        snake.appendleft(new_head)
        board[new_head[0]][new_head[1]] = 0
    else :
        snake.appendleft(new_head)
        snake.pop()
    if commands and int(commands[0][0]) == time:
        cmd = commands.popleft()[1]
        if cmd == 'D':
            direction = (direction+1) % 4
        if cmd == 'L':
            direction = (direction-1) % 4
    
print(time)