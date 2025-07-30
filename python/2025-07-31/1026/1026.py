# BOJ 1026
import sys

n = int(input())
a = list(map(int, sys.stdin.readline().split()))
b = list(map(int, sys.stdin.readline().split()))

a.sort(key=lambda a: -a) # 그냥 a.sort(reverse=True)하면 된다.
b.sort()

print(sum(x*y for x,y in zip(a,b)))