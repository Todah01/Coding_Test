#if 0
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;

    if (accumulate(works.begin(), works.end(), 0) <= n)
        return 0;

    for (auto work : works)
        pq.push(work);

    while (n) {
        pq.push(pq.top() - 1);
        pq.pop();
        n--;
    }

    while (!pq.empty()) {
        answer += pow(pq.top(), 2);
        pq.pop();
    }

    return answer;
}
#endif