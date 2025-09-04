n, m, r = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(n)]

for _ in range(r):
    for i in range(min(n,m)//2):
        r, c = i, i
        tmp = board[r][c]

        for j in range(i+1, n-i):
            r = j
            prev = board[r][c]
            board[r][c] = tmp
            tmp = prev

        for j in range(i+1, m-i):
            c = j
            prev = board[r][c]
            board[r][c] = tmp
            tmp = prev

        for j in range(i+1, n-i):
            r = n-j-1
            prev = board[r][c]
            board[r][c] = tmp
            tmp = prev

        for j in range(i+1, m-i):
            c = m-j-1
            prev = board[r][c]
            board[r][c] = tmp
            tmp = prev

for i in range(n) :
    print(*board[i])
