

n, m, b = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(n)]


minimal = 256*250000*2
tmp = 0
for target in range(257):
    add = 0
    remove = 0
    for i in range(n):
        for j in range(m):
            h = board[i][j]
            if h < target :
                add += target-h
            else :
                remove += h-target
    # print(f"add: {add} remove: {remove} inv: {inv}")
    if add > b+remove :
        # print("continue")
        continue
    calc_t = add*1+ remove*2
    if calc_t <= minimal :
        minimal = calc_t
        tmp = target
    # print(minimal, tmp)
    # print("------------")

print(minimal, tmp)





