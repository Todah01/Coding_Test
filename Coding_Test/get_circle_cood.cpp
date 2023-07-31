#if 0
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    for (int t = 1; t <= r2; ++t)
    {
        int h2 = floor(sqrt(pow(r2, 2) - pow(t, 2)));
        int h1 = (t < r1) ? ceil(sqrt(pow(r1, 2) - pow(t, 2))) : 0;
        answer += h2 - h1 + 1;
    }
    return 4 * answer;
}
#endif