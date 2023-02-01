#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int idx = 0;
    vector<int> temp;

    sort(score.begin(), score.end(), greater<>());

    while (idx < score.size())
    {
        temp.push_back(score[idx]);

        if (temp.size() == m)
        {
            answer += *min_element(temp.begin(), temp.end()) * m;
            temp.clear();
        }

        // if(score.size() - idx < m - 1)
        //     break;

        idx++;
    }

    return answer;
}
#endif

#pragma region Using %
#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;

    sort(score.begin(), score.end(), greater());


    /*for(int i = 0 ; i < score.size() ; i += m){
        answer += score[i + m - 1] * m;
    }*/
    int box_num = score.size() / m;
    int cur = m - 1;
    for (int i = 0; i < box_num; i++) {
        answer += score[cur] * m;
        cur += m;
    }

    return answer;
}

#endif
#pragma endregion

#pragma region Using queue
#if 0
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> pq;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    for (int i = 0; i < score.size(); i++)
        pq.push(score[i]);
    while (pq.size() >= m) {
        for (int i = 0; i < m - 1; i++) pq.pop();
        answer += pq.top() * m;
        pq.pop();
    }
    return answer;
}
#endif
#pragma endregion
