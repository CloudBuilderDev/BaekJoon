n = int(input())
k = int(input())

board = [[0]*(n+1) for _ in range(n+1)]

num = 1
step = 1
dr = [-1, 0, 1, 0] #u, r, d, l
dc = [0, 1, 0, -1]

center = -(-n//2)
r, c = center, center 
board[r][c] = num
num +=1
direct = 0
while num <= n*n :
    for _ in range(2):
        for i in range(step):
            if num > n*n : 
                break
            r, c = r+dr[direct], c+dc[direct]
            # print(f"new current : ({r}, {c})")
            board[r][c] = num
            # print(*board[1:], sep='\n')
            num+=1
        direct = (direct+1) %4
    step+=1   


for row in board[1:]:
    print(*row[1:])

for i in range(n+1):
    for j in range(n+1):
        if board[i][j] == k:
            print(i, j)
