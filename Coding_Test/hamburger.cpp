#if 0
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int idx = 0;
    vector<int> burger = { 1, 2, 3, 1 };
    vector<int> countertop;

    while (idx < ingredient.size())
    {
        countertop.push_back(ingredient[idx]);

        if (countertop.size() >= burger.size())
        {
            vector<int> slice(countertop.end() - 4, countertop.end());

            if (slice == burger)
            {
                answer++;
                countertop.erase(countertop.end() - 4, countertop.end());
            }
        }

        idx++;
    }

    return answer;
}
#endif

#pragma region Using back
#if 0
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v = { -1 };
    for (int x : ingredient) {
        if (v.back() == 1 && x == 2) v.back() = 12;
        else if (v.back() == 12 && x == 3) v.back() = 123;
        else if (v.back() == 123 && x == 1) answer++, v.pop_back();
        else v.push_back(x);
    }

    return answer;
}
#endif
#pragma endregion
