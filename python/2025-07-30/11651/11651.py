# BOJ 11651
# 10^8
import sys
n = int(input())
points = [tuple(map(int, sys.stdin.readline().split())) for _ in range(n)]
points.sort(key=lambda p: (p[1], p[0]))

for x,y in points:
    print(x,y)