from collections import deque

n, m = map(int,input().split())
points = list(map(int, input().split()))

q = deque([i for i in range(1, n+1)]) 
cnt = 0

while points:
    target = points.pop(0)

    if q[0] == target :
        q.popleft()
    else :
        idx = 1
        while idx < n:
            if q[idx] == target:
                break
            else : idx+=1 
        if idx <= len(q)-idx:
            q.rotate(-idx)
            cnt+=idx
        else:
            q.rotate(len(q)-idx)
            cnt += len(q)-idx
        q.popleft()
        
print(cnt)

