n = int(input())
from collections import deque
cards = deque([i for i in range(1,n+1)])
for _ in range(len(cards)):
    if len(cards) == 1 : break
    cards.popleft()
    tmp = cards.popleft()
    cards.append(tmp)
print(*cards)
