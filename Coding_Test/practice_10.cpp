#if 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int cnt = 0;
    int i = 0;
    vector<int> under_K;

    //예외 처리 1 : 이미 모든 음식의 스코빌 지수가 7 이상인 경우
    for (auto& iter : scoville)
    {
        if (iter < K) cnt++;
    }
    if (cnt == 0) return answer;

    //오름차순 정렬
    sort(scoville.begin(), scoville.end());

    //수행 과정
    while (1)
    {
        int new_scoville = 0;

        if (i > scoville.size()) break;
        else if (i > 0)
        {
            if (under_K.back() >= K) break;
        }

        if (i == 0)
        {
            new_scoville = scoville[0] + (scoville[1] * 2);
            under_K.push_back(new_scoville);
            answer++;
        }
        else if (i + 1 < scoville.size())
        {
            if (under_K[i - 1] < scoville[i + 1])
            {
                new_scoville = under_K[i - 1] + (scoville[i + 1] * 2);
            }
            else
            {
                new_scoville = scoville[i + 1] + (under_K[i - 1] * 2);
            }
            under_K.push_back(new_scoville);
            answer++;
        }
        i++;
    }

    //예외 처리 1 : 모든 음식을 다 섞었음에도 스코빌 지수가 7 미만인 경우
    if (answer == 0) return -1;
    else return answer;
}

int main()
{
    vector<int> scoville = { 1,2,3,9,10,12 };
    int K = 7;

    //solution(scoville, K);

    cout << solution(scoville, K);
}
#endif

#if 0
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while (pq.top() < K)
    {
        if (pq.size() == 1) return -1;

        int first_val = pq.top();
        pq.pop();
        int second_val = pq.top();
        pq.pop();

        int new_scoville = first_val + (second_val * 2);
        pq.push(new_scoville);

        answer++;
    }
    return answer;
}

int main()
{
    vector<int> scoville = { 1,2,3,9,10,12 };
    int K = 7;

    cout << solution(scoville, K);
}
#endif