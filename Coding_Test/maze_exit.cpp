#if 0
from collections import deque

def bfs(maps, arive) :
    r, c = len(maps), len(maps[0])
    visited = [[0 if maps[i][j] != 'X' else 'X' for j in range(c)]for i in range(r)]
    sp = [[i, j]for i in range(r) for j in range(c) if maps[i][j] == 'S']
    lp = [[i, j]for i in range(r) for j in range(c) if maps[i][j] == 'L']
    q = deque()

    if arive == 'E': q.append(lp[0])
        elif arive == 'L' : q.append(sp[0])

        dx = [1, -1, 0, 0]
        dy = [0, 0, -1, 1]

        while q :
            cr, cc = q.popleft()
            for idx in range(4) :
                dr = cr + dx[idx]
                dc = cc + dy[idx]
                if 0 <= dr < r and 0 <= dc < cand visited[dr][dc] != 'X' :
                    if maps[dr][dc] == arive :
                        visited[dr][dc] = visited[cr][cc] + 1
                        return visited[dr][dc]
                    else :
                        visited[dr][dc] = visited[cr][cc] + 1
                        q.append([dr, dc])
                        return 0

                        def solution(maps) :
                        s_to_l_length = bfs(maps, 'L')
                        l_to_e_length = bfs(maps, 'E')

                        if not s_to_l_length or not l_to_e_length :
                            return -1
                        else:
return s_to_l_length + l_to_e_length
#endif