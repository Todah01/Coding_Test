#if 0
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for (long long x = 0; x < d + 1; x += k) {
        long long maxY = sqrt(pow(d, 2) - pow(x, 2));
        answer += (maxY / k) + 1;
    }
    return answer;
}
#endif