#if 0
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int toIdx(char dir) {
    switch (dir)
    {
    case 'U': return 0;
    case 'D': return 1;
    case 'R': return 2;
    case 'L': return 3;
    }
}

int solution(string dirs) {
    int dir_idx, cur_x = 0, cur_y = 0, temp_x, temp_y;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    set<pair<pair<int, int>, pair<int, int>>> save_loc;

    for (char dir : dirs)
    {
        dir_idx = toIdx(dir);
        temp_x = cur_x + dx[dir_idx];
        temp_y = cur_y + dy[dir_idx];

        if (!(temp_x <= 5 && temp_x >= -5 && temp_y <= 5 && temp_y >= -5))
            continue;

        if (save_loc.find({ {cur_x, cur_y}, {temp_x, temp_y} }) == save_loc.end()
            && save_loc.find({ {temp_x, temp_y}, {cur_x, cur_y} }) == save_loc.end())
        {
            save_loc.insert({ {cur_x, cur_y}, {temp_x, temp_y} });
        }

        cur_x = temp_x;
        cur_y = temp_y;
    }

    return save_loc.size();
}
#endif

#pragma region MyRegion
#if 0
#include <string>
#include <set>
using namespace std;
int toIdx(char ch) {
    switch (ch) {
    case 'R': return 0;
    case 'L': return 1;
    case 'U': return 2;
    case 'D': return 3;
    }
}
int solution(string dirs) {
    char ch;
    int answer = 0, i, x = 0, y = 0, ty, tx, dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 }, idx, a, b;
    set<pair<int, int>> ans;
    for (i = 0;i < dirs.length();i++) {
        ch = dirs[i];
        idx = toIdx(ch);
        tx = x + dx[idx], ty = y + dy[idx];
        if (!(-5 <= ty && ty <= 5 && -5 <= tx && tx <= 5)) continue;
        a = x * 10000 + y;
        x = tx, y = ty;
        b = x * 10000 + y;
        if (ans.find({ a,b }) == ans.end() && ans.find({ b,a }) == ans.end())
            ans.insert({ a,b });
    }
    return answer = (int)ans.size();
}

#endif
#pragma endregion
