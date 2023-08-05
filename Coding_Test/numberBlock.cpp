#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_N = 1e7;

inline int findNum(int here) {
    for (int i = 2; sqrt(i) <= here; i++) {
        if (here % i == 0 && here / i <= MAX_N)
            return here / i;
    }
    return 1;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    if (begin == 1) {
        answer.push_back(0);
        begin++;
    }

    for (int i = begin; i <= end; i++) {
        answer.push_back(findNum(i));
    }
    return answer;
}
#endif