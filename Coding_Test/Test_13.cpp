// 1번
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int solution(int C, int B) {
    int answer = 0;
    queue<pair<int, int>> check;
    vector<map<int, bool>> visited(200001);
    
    check.push({ B, answer });

    while (C <= 200000)
    {
        C += answer;

        if (visited[C].count(answer))
            return answer;

        for (int i = 0; i < check.size(); i++)
        {
            int cur_loc = check.front().first;
            int cur_time = check.front().second;
            check.pop();

            int new_time = cur_time + 1;

            int new_brown_loc_1 = cur_loc + 1;
            if ((0 <= new_brown_loc_1 && new_brown_loc_1 <= 200000) && !(visited[new_brown_loc_1].count(new_time)))
            {
                check.push({ new_brown_loc_1, new_time });
                visited[new_brown_loc_1][new_time] = true;
            }

            int new_brown_loc_2 = cur_loc - 1;
            if ((0 <= new_brown_loc_2 && new_brown_loc_2 <= 200000) && !(visited[new_brown_loc_2].count(new_time)))
            {
                check.push({ new_brown_loc_2, new_time });
                visited[new_brown_loc_2][new_time] = true;
            }

            int new_brown_loc_3 = cur_loc * 2;
            if ((0 <= new_brown_loc_3 && new_brown_loc_3 <= 200000) && !(visited[new_brown_loc_3].count(new_time)))
            {
                check.push({ new_brown_loc_3, new_time });
                visited[new_brown_loc_3][new_time] = true;
            }
        }

        answer++;
    }

    return answer;
}

int main()
{
    cout << solution(11, 2) << endl; // 정답 : 5
    cout << solution(10, 3) << endl; // 정답 : 3
    cout << solution(51, 50) << endl; // 정답 : 8
    cout << solution(550, 500) << endl; // 정답 : 28
}
#endif

// 2번
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int get_direction(int dir)
{
    if (dir % 2 == 0) return dir + 1;
    else return dir - 1;
}

int solution(int K, vector<vector<int>> chess_map, vector<vector<int>> start_horse) {
    int answer = 1;
    int n = chess_map.size();

    vector<vector<vector<int>>> horse_map(n, vector<vector<int>>(n, vector<int>(n)));

    for (int i = 0; i < K; i++)
        horse_map[start_horse[i][0]][start_horse[i][1]].push_back(i);

    while (answer <= 1000)
    {
        for (int i = 0; i < K; i++)
        {
            int cur_r = start_horse[i][0];
            int cur_c = start_horse[i][1];
            int cur_d = start_horse[i][2];

            int new_r = cur_r + dr[cur_d];
            int new_c = cur_c + dc[cur_d];

            if (!(0 <= new_r && new_r < n) || !(0 <= new_c && new_c < n) || chess_map[new_r][new_c] == 2)
            {
                int new_d = get_direction(cur_d);

                start_horse[i][2] = new_d;
                new_r = cur_r + dr[new_d];
                new_c = cur_c + dc[new_d];

                if (!(0 <= new_r && new_r < n) || !(0 <= new_c && new_c < n) || chess_map[new_r][new_c] == 2)
                    continue;
            }

            vector<int> moving_arr;
            for (int horse_idx = 0; horse_idx < horse_map[cur_r][cur_c].size(); i++)
            {
                if (i == horse_map[cur_r][cur_c][horse_idx])
                {
                    moving_arr = vector<int>(horse_map[cur_r][cur_c].begin() + horse_idx, horse_map[cur_r][cur_c].end());
                    horse_map[cur_r][cur_c] = vector<int>(horse_map[cur_r][cur_c].begin(), horse_map[cur_r][cur_c].begin() + horse_idx);
                    break;
                }
            }

            if (chess_map[new_r][new_c] == 1)
                reverse(moving_arr.begin(), moving_arr.end());

            for (auto iter : moving_arr)
            {
                horse_map[new_r][new_c].push_back(iter);
                start_horse[iter][0] = new_r;
                start_horse[iter][1] = new_c;
            }

            if (horse_map[new_r][new_c].size() >= 4)
                return answer;
        }
        answer++;
    }

    return -1;
}

int main()
{
    int K = 4;
    vector<vector<int>> chess_map_1 = { {0, 0, 2, 0},
                                        {0, 0, 1, 0},
                                        {0, 0, 1, 2},
                                        {0, 2, 0, 0} };

    vector<vector<int>> chess_map_2 = { {0, 0, 0, 0},
                                        {0, 0, 0, 0},
                                        {0, 0, 0, 0},
                                        {0, 0, 0, 0} };

    vector<vector<int>> start_horse_1 = { {0, 0, 0},
                                          {0, 1, 0},
                                          {0, 2, 0},
                                          {2, 2, 2} };

    vector<vector<int>> start_horse_2 = { {1, 0, 0},
                                          {2, 1, 2},
                                          {1, 1, 0},
                                          {3, 0, 1} };

    vector<vector<int>> start_horse_3 = { {0, 1, 0},
                                          {1, 1, 0},
                                          {0, 2, 0},
                                          {2, 2, 2} };

    vector<vector<int>> start_horse_4 = { {0, 1, 0},
                                          {0, 1, 1},
                                          {0, 1, 0},
                                          {2, 1, 2} };

    cout << solution(K, chess_map_2, start_horse_1) << endl; // 정답 : 2
    //cout << solution(K, chess_map_1, start_horse_2) << endl; // 정답 : -1
    //cout << solution(K, chess_map_2, start_horse_3) << endl; // 정답 : 9
    //cout << solution(K, chess_map_2, start_horse_4) << endl; // 정답 : 3
}
#endif