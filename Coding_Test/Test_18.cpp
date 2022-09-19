// 1번
#if 0
#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    return answer;
}

int main()
{
    cout << solution("()()"); // 정답 : true
    cout << solution("(())()"); // 정답 : true
    cout << solution(")()("); // 정답 : false
    cout << solution("(()("); // 정답 : false
}
#endif

// 2번
#if 0
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    return answer;
}

int main()
{
    cout << solution({ 70, 50, 80, 50 }, 100); // 정답 : 3
    cout << solution({ 70, 80, 50 }, 100); // 정답 : 3
}
#endif