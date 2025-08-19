#n, k = map(int, input().split())
#belt = list(map(int, input().split()))

#start = 0
#end = n - 1
#robots = [False] * n  # 로봇이 올라갈 수 있는 위치는 0 ~ n-1

#step = 0

#while True:
    #step += 1

    ## 1. 벨트 회전
    #start = (start - 1) % (2 * n)
    #end = (end - 1) % (2 * n)
    #robots = [False] + robots[:-1]  # 로봇도 함께 회전
    #robots[-1] = False  # 내리는 위치에서는 무조건 로봇 제거

    ## 2. 로봇 이동
    #for i in range(n - 2, -1, -1):  # 뒤에서부터 로봇이 내리는 자리를 제외한 n-2번째 자리의 로봇부터 이동 시도
        #curr_idx = (start + i) % (2 * n)
        #next_idx = (start + i + 1) % (2 * n)

        #if robots[i] and not robots[i + 1] and belt[next_idx] > 0:
            #robots[i] = False
            #robots[i + 1] = True
            #belt[next_idx] -= 1
    #robots[-1] = False  # 내리는 위치에서 로봇 제거

    ## 3. 로봇 올리기
    #if belt[start] > 0 and not robots[0]:
        #robots[0] = True
        #belt[start] -= 1

    ## 4. 종료 조건
    #if belt.count(0) >= k:
        #print(step)
        #break

from collections import deque

n, k = map(int, input().split())
belt = deque(map(int, input().split()))
robots = deque([False]*n)

step = 0

while True:
    step +=1

    belt.rotate(1)
    robots.rotate(1)
    robots[-1] = False

    for i in range(n-2, -1, -1):
        if robots[i] and not robots[i+1] and belt[i+1] >0:
            robots[i] = False
            robots[i+1] = True
            belt[i+1] -=1
    robots[-1] = False

    if belt[0] > 0 and not robots[0]:
        robots[0] = True
        belt[0] -= 1
    if belt.count(0) >= k:
        print(step)
        break