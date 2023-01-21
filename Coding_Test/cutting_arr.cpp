#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i < right + 1; i++)
        answer.push_back(max((i % n) + 1, (i / n) + 1));

    return answer;
}
#endif

#pragma region Another
#if 0

#endif
#pragma endregion
