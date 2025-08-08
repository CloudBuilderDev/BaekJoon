n, m = map(int, input().split())
list = [list(input()) for _ in range(n)]

min_cnt = 64
for x in range(n-7):
    for y in range(m-7):
        start = list[x][y]
        cnt1 = 0
        cnt2 = 0
        for i in range(8):
            for j in range(8):
                current = list[x+i][y+j]
                if(i+j) % 2 == 0 :
                    if current != 'W':
                        cnt1+=1
                    if current != 'B':
                        cnt2+=1
                else :
                    if current != 'B':
                        cnt1+=1
                    if current != 'W':
                        cnt2+=1 
        min_cnt = min(min_cnt, cnt1,cnt2)     

print(min_cnt) 