#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    for (int i = 1; i < land.size(); i++)
        for (int j = 0; j < 4; j++)
        {
            int temp = land[i - 1][j];
            land[i - 1][j] = -1;
            land[i][j] += max({ land[i - 1][0],land[i - 1][1],land[i - 1][2],land[i - 1][3] });
            land[i - 1][j] = temp;
        }

    return *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());
}
#endif

#pragma region Using cutting arr
#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    for (int i = 1; i < land.size(); i++)
        for (int j = 0; j < land[i - 1].size(); j++)
        {
            vector<int> temp = land[i - 1];
            temp.erase(temp.begin() + j);
            land[i][j] += *max_element(temp.begin(), temp.end());
        }

    return *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());
}
#endif
#pragma endregion
