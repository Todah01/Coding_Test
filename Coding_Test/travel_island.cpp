#if 0
from collections import deque

def solution(maps) :
    answer = []
    row, col = len(maps), len(maps[0])
    visited = [[0 for c in range(col)]for r in range(row)]
    dx = [1, -1, 0, 0]
    dy = [0, 0, -1, 1]

    visited[0][0] = 1
    QUEUE = [(0, 0)]

    for r in range(row) :
        for c in range(col) :


            while QUEUE :
                cv, cr = QUEUE.pop()

                for idx in range(4) :
                    dr = cr + dx[idx]
                    dc = cc + dy[idx]
                    if dr >= 0 and dr < rowand dc >= 0 and dc < coland maps[dr][dc] != 0 and visited[dr][dc] != 1 :
                        QUEUE.append((dr, dc))
#endif