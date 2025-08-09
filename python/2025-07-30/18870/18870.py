# BOJ 18870
import sys
n = int(input())

points = list(map(int, sys.stdin.readline().split()))
sorted_set = sorted(set(points))

result = {value: index for index, value in enumerate(sorted_set)}

for p in points:
    print(result[p], end=" ")

# enumerate(sorted_set)은 다음과 같이 (index, value) 꼴의 튜플로 반환한다. 
# sorted_unique = [-10, -9, 2, 4]
# => (0,-10), (1, -9), (2, 2), (3, 4)