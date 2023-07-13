#if 0
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> heap;

    for (int idx = 0; idx < enemy.size(); idx++) {
        heap.push(enemy[idx]);
        if (n - enemy[idx] >= 0) {
            n -= enemy[idx];
        }
        else {
            while (!heap.empty() && k > 0 && n - enemy[idx] < 0) {
                n += heap.top();
                heap.pop();
                k -= 1;
            }

            n -= enemy[idx];
        }

        if (n < 0)
            return idx;
    }

    return enemy.size();
}
#endif

#if 0
#include <queue>
#include <vector>

using namespace std;

int solution(int n, int k, vector<int> enemy)
{
    int answer = 0;

    int idx = 0;
    priority_queue<int> pq;
    while (idx < enemy.size())
    {
        if (n < enemy[idx] && k <= 0) break;
        n -= enemy[idx];
        pq.push(enemy[idx]);
        if (n < 0)
        {
            n += pq.top();
            pq.pop();
            k--;
        }
        idx++;
    }
    answer = idx;

    return answer;
}
#endif