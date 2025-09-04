k = int(input())

ls = []
for _ in range(k):
    tmp = int(input())
    if tmp == 0 :
        ls.pop()
    else: 
        ls.append(tmp)
print(sum(ls))
