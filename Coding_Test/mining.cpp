#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct MineSet
{
    int d_f = 0;
    int i_f = 0;
    int s_f = 0;
    int weight = 0;
};

bool cmp(MineSet m1, MineSet m2)
{
    return m1.weight > m2.weight;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;

    vector<MineSet> mineset_list;
    int total_picks = picks[0] + picks[1] + picks[2];

    for (int i = 0; i < minerals.size(); i += 5)
    {
        if (total_picks <= 0)
            break;

        // 5개의 광물을 각각의 곡괭이를 사용했을때의 각각의 피로도
        MineSet mineset;

        for (int j = 0; j < 5; ++j)
        {
            auto mineral = i + j < minerals.size() ? minerals.begin() + i + j : minerals.end();

            if (mineral == minerals.end())
                continue;

            if (*mineral == "diamond")
            {
                mineset.d_f += 1;
                mineset.i_f += 5;
                mineset.s_f += 25;
                mineset.weight += 25;
            }
            else if (*mineral == "iron")
            {
                mineset.d_f += 1;
                mineset.i_f += 1;
                mineset.s_f += 5;
                mineset.weight += 5;
            }
            else if (*mineral == "stone")
            {
                mineset.d_f += 1;
                mineset.i_f += 1;
                mineset.s_f += 1;
                mineset.weight += 1;
            }
        }
        total_picks--;
        mineset_list.push_back(mineset);
    }

    sort(mineset_list.begin(), mineset_list.end(), cmp);

    for (const auto& ms : mineset_list)
    {
        if (picks[0] > 0)
        {
            picks[0]--;
            answer += ms.d_f;
        }
        else if (picks[1] > 0)
        {
            picks[1]--;
            answer += ms.i_f;
        }
        else if (picks[2] > 0)
        {
            picks[2]--;
            answer += ms.s_f;
        }
    }

    return answer;
}
#endif