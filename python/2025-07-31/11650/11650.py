# BOJ 11650
# 1s, 10^8
# 1<=N<=10^5
import sys
n = int(input())
points = [(int(x), int(y)) for _ in range(n) for x,y in [sys.stdin.readline().split()]]
points.sort()

for x,y in points:
    print(x,y)