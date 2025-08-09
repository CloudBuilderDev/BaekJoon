n,m,x,y,k = map(int,input().split())
maps = [list(map(int, input().split())) for _ in range(n)]

#print(maps)
command = list(map(int, input().split()))
directions = [(0,1), (0,-1), (-1,0), (1,0)] # 1:동 2:서 3:북 4:남

#print(command)
from collections import deque
ew = deque([0,0,0,0]) # 밑, 서, 위, 동
sn = deque([0,0,0,0]) # 북, 위 , 남, 밑

for c in command:
    #print(f"현재 주사위 위치 : ({x},{y})")
    direction = c
    #print("방향: ", direction)
    dx, dy = directions[direction-1] 
    #print("dx dy: ", dx, dy)
    if not(0<= x+dx<=n-1 and 0<= y+dy <=m-1):
        #print("지도의 바깥으로 접근하려 함")
        continue
    x += dx
    y += dy
    #print(f"new (x, y) : ({x}, {y})")    
    #print("회전하기 전")
    #print(ew)
    #print(sn)

    if c==1:
        ew.rotate(1)
        sn[1] = ew[2]
        sn[3] = ew[0]
    if c==2:
        ew.rotate(-1)
        sn[1] = ew[2]
        sn[3] = ew[0]
    if c==3:
        sn.rotate(1)
        ew[0] = sn[3]    
        ew[2] = sn[1]
    if c==4:
        sn.rotate(-1)
        ew[0] = sn[3]    
        ew[2] = sn[1]
    #print("회전한 후")
    #print("밑동위서")
    #print(*ew)
    #print("북위남밑")
    #print(*sn)
    
    #print(f"새 위치의 지도에 새겨진 정수 값: {maps[x][y]}")
    if maps[x][y] != 0 :
        ew[0] = maps[x][y]
        sn[3] = maps[x][y]
        maps[x][y] = 0
    else:
        maps[x][y] = ew[0]
    #print("새로 밑면 새겨진 후 ")
    #print("밑동위서")
    #print(*ew)
    #print("북위남밑")
    #print(*sn)
    #print(f"주사위 윗면 출력 : {ew[2], sn[1]}")
    #print("------------------------------")
    print(ew[2])






#https://edder773.tistory.com/210 그냥 이렇게 하는게 더 쉽겠다... 