// 풀이1 - 조합
#if 0
#include <algorithm>
#include <vector>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int max_passed = 0;
    sort(begin(dungeons), end(dungeons));
    do {
        int current_k = k;
        int passed = 0;
        for (const auto& dungeon : dungeons) {
            if (dungeon.at(0) <= current_k) {
                ++passed;
                current_k -= dungeon.at(1);
            }
        }
        if (passed > max_passed) {
            max_passed = passed;
        }
    } while (next_permutation(begin(dungeons), end(dungeons)));
    return max_passed;
}
#endif

// 풀이2 - dfs
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check[8] = { false, };
int max_cnt = 0;

// dfs를 통해 남은 피로도가 0 이상이면서 유저가 탐험할 수 있는 최대 던전 수를 return 한다.
int try_dungeon(int adventure_cnt, int fatigue_amount, int dungeon_size, vector<vector<int>> dungeons)
{
    for (int i = 0; i < dungeon_size; i++)
    {
        if (!check[i] && dungeons[i][0] <= fatigue_amount)
        {
            check[i] = true;
            //cout << "CLEAR" << endl;
            try_dungeon(adventure_cnt + 1, fatigue_amount - dungeons[i][1], dungeon_size, dungeons);
            check[i] = false;
        }
        max_cnt = max(max_cnt, adventure_cnt);
    }
    return max_cnt;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int dungeon_size = dungeons.size();

    answer = try_dungeon(0, k, dungeon_size, dungeons);

    return answer;
}
#endif