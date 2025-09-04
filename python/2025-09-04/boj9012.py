t = int(input())

def check (str):
    stack = []
    for c in str:
        if c == '(':
            stack.append(c)
        elif c == ')':
            if not stack:
                return False
            stack.pop()
    if stack : return False
    return True

for _ in range(t):
    str = list(input())
    if check(str) : print("YES")
    else : print("NO")
    