import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
def in_range(x,y):
    return 1<=x<=n and 1<=y<=m

board = [[0]*(m+1)] + [[0] + list(map(int, input().split())) for _ in range(n)]

#    동, 북, 남, 서
dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]

r, c = 1, 1
d = 0
dice = [1,2,3,4,5,6] # d, n, e, w, s, u

for _ in range(k):
    nr, nc = r+dr[d], c+dc[d]
    if not in_range(nr,nc):
        nr, nc = r+dr[(d+3)%4], c+dc[(d+3)%4]
    

def calculate_score(x,y):
    pass 

print(*board,sep="\n")