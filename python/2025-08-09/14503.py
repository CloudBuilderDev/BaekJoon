import sys
input = sys.stdin.readline

n, m = map(int, input().split())
r, c, d = map(int, input().split())
room = [list(map(int, input().split())) for _ in range(n)]

# 북, 동, 남, 서
dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

def in_range(x, y):
    return 0 <= x < n and 0 <= y < m

cnt = 0
while True:
    # 1. 현재 칸이 아직 청소되지 않은 경우, 청소한다.
    if room[r][c] == 0:
        room[r][c] = 2   # 2: 청소됨
        cnt += 1

    # 2. 주변 4칸 중 청소되지 않은 빈 칸(=0)이 있는지 확인
    found = False
    for _ in range(4):
        # 반시계 회전
        d = (d + 3) % 4
        nr, nc = r + dr[d], c + dc[d]
        if in_range(nr, nc) and room[nr][nc] == 0:
            # 앞쪽이 청소되지 않은 빈 칸이면 전진
            r, c = nr, nc
            found = True
            break

    if found:
        continue

    # 2-(b) 네 방향 모두 청소 불가 → 후진 시도 (방향 유지)
    back_d = (d + 2) % 4
    br, bc = r + dr[back_d], c + dc[back_d]
    if not in_range(br, bc) or room[br][bc] == 1:
        # 뒤가 벽이면 종료
        break
    # 뒤가 벽이 아니면 한 칸 후진
    r, c = br, bc

print(cnt)
