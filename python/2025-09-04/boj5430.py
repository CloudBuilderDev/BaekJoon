import sys
from collections import deque

input = sys.stdin.readline

t = int(input())
for _ in range(t):
    p = input().strip()           
    n = int(input())              
    s = input().strip()           

    if s == "[]":
        arr = deque()
    else:
        arr = deque(map(int, s[1:-1].split(',')))

    rev = False
    error = False

    for op in p:
        if op == 'R':
            rev = not rev
        elif op == 'D':
            if not arr:
                print("error")
                error = True
                break            
            if not rev:
                arr.popleft()
            else:
                arr.pop()

    if error:
        continue

    if rev:
        arr.reverse()             
    print("[" + ",".join(map(str, arr)) + "]")
