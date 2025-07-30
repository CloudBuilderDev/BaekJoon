#n = int(input())
#h = []
#w = [] 
#r = [1]*n

#for i in range(n):
    #tmp_h, tmp_w = list(map(int, input().split()))
    #h.append(tmp_h)
    #w.append(tmp_w)
#for i in range(n):
    #for j in range(n):
        #if(w[i]<w[j] and h[i]<h[j]) : 
            #r[i]+=1

#for i in range(n):
    #print(r[i], end=" ")        


# more improve code
n = int (input())
people = [tuple(map(int, input().split())) for _ in range(n)]
ranks = [1] * n

for i in range(n):
    for j in range(n) : 
        if people[i][0] < people[j][0] and people[i][1] < people[j][1]:
            ranks[i] += 1
print(*ranks)