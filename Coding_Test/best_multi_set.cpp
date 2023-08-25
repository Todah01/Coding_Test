#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (s / n <= 0)
        return { -1 };

    for (int i = 0; i < n; i++)
        answer.push_back(s / n);

    if (s % n == 0) {
        sort(answer.begin(), answer.end());
        return answer;
    }

    for (int i = 0; i < s % n; i++) {
        answer[i]++;
    }

    sort(answer.begin(), answer.end());
    return answer;
}
#endif