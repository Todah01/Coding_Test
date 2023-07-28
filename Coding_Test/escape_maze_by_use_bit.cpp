#if 0
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int n = park.size(), m = park[0].size(), x, y;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        if (park[i][j] == 'S') {
            x = i;
            y = j;
        }
    }

    const char* s = "NESW";

    for (auto& route : routes) {
        char op = route[0];
        int len = route[2] - 48;

        int nx = x, ny = y;
        bool f = 1;
        for (int i = 0; i < len; ++i) {
            nx += "0121"[strchr(s, op) - s] - 49;
            ny += "1210"[strchr(s, op) - s] - 49;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || park[nx][ny] == 'X') {
                f = 0;
                break;
            }
        }

        if (f) x = nx, y = ny;
    }

    return { x, y };
}
#endif