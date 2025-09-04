n, w, l = map(int , input().split())
trucks = list(map(int, input().split()))

bridge = [0] * w
time = 0

while bridge :
    time +=1
    bridge.pop(0)
    if trucks:
        if sum(bridge) + trucks[0] <= l:
            bridge.append(trucks.pop(0))
            print(bridge)
        else:
            bridge.append(0)
            print(bridge)
print(time)


 
    
