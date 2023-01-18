#if 0
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    vector<pair<int, string>> game_vector, target_vector;

    for (int idx = 0; idx < n; idx++)
    {
        game_vector.push_back({ idx + 1, "" });
        if (idx + 1 == a || idx + 1 == b)
            target_vector.push_back({ idx + 1, "target" });
    }

    while (!(target_vector[1].first - target_vector[0].first == 1
        && target_vector[0].first % 2 != 0))
    {
        answer++;
        int low_number = target_vector[0].first;
        int high_number = target_vector[1].first;

        if (low_number % 2 == 0)
            target_vector[0].first = (low_number / 2);
        else
            target_vector[0].first = (low_number / 2) + 1;

        if (high_number % 2 == 0)
            target_vector[1].first = (high_number / 2);
        else
            target_vector[1].first = (high_number / 2) + 1;
    }

    return answer;
}
#endif

#pragma region Simple
#if 0
int solution(int n, int a, int b)
{
    a--;
    b--;
    int answer = 0;
    while (a != b) {
        a = a / 2;
        b = b / 2;
        answer++;
    }
    return answer;
}
#endif
#pragma endregion
