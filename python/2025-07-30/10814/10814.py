# BOJ 10814/ 2*10^8
# 1 <= N <= 10^5
import sys
n = int(sys.stdin.readline())
#clients = [tuple((int(age), name) for age, name in (sys.stdin.readline().split()) for _ in range(n))]
# 위의 경우, 갑자기 이전에 stdout된 것들이 stdin되어버림

clients = [(int(age), name) for _ in range(n) for age, name in [sys.stdin.readline().split()]]

clients.sort(key=lambda x: x[0])
for age, name in clients:
    print(age, name)