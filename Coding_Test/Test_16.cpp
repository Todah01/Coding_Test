// 1번
#if 0
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    return answer;
}

int main()
{
    solution({ 3,2,7,2 }, { 4,6,5,1 }); // 정답 : 2
    solution({ 1,2,1,2 }, { 1,10,1,2 }); // 정답 : 7
    solution({ 1,1 }, { 1,5 }); // 정답 : -1
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