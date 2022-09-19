// 1번
#if 0
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> queue_1{ {begin(queue1), end(queue1)} };
    queue<int> queue_2{ {begin(queue2), end(queue2)} };

    long long queue_1_sum = accumulate(queue1.begin(), queue1.end(), 0);
    long long queue_2_sum = accumulate(queue2.begin(), queue2.end(), 0);

    if ((queue_1_sum + queue_2_sum) % 2 == 1) return -1;
    if (queue_1_sum == queue_2_sum) return answer;

    while (queue_1_sum != queue_2_sum)
    {
        if (answer > queue1.size() + queue2.size() + 2) return -1;

        if (queue_1_sum < queue_2_sum)
        {
            queue_1.push(queue_2.front());
            queue_1_sum += queue_2.front();
            queue_2_sum -= queue_2.front();
            queue_2.pop();
        }
        else
        {
            queue_2.push(queue_1.front());
            queue_2_sum += queue_1.front();
            queue_1_sum -= queue_1.front();
            queue_1.pop();
        }

        answer += 1;
    }
    return answer;
}

int main()
{
    cout << solution({ 3,2,7,2 }, { 4,6,5,1 }) << endl; // 정답 : 2
    cout << solution({ 1,2,1,2 }, { 1,10,1,2 }) << endl; // 정답 : 7
    cout << solution({ 1,1 }, { 1,5 }) << endl; // 정답 : -1
}
#endif

// 2번
#if 0
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    return answer;
}

int main()
{
    solution({ "banana", "apple", "rice", "pork", "pot" }, { 3, 2, 2, 2, 1 },
        {"chicken", "apple", "apple", "banana", "rice",
        "apple", "pork", "banana", "pork", "rice",
        "pot", "banana", "apple", "banana"}); // 정답 : 3
    
    solution({ "apple" }, { 10 },
        { "banana","banana", "banana", "banana", "banana",
        "banana", "banana", "banana", "banana", "banana" }); // 정답 : 0
}
#endif