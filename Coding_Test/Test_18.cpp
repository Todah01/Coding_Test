// 1��
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
    cout << solution("()()"); // ���� : true
    cout << solution("(())()"); // ���� : true
    cout << solution(")()("); // ���� : false
    cout << solution("(()("); // ���� : false
}
#endif

// 2��
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
    cout << solution({ 70, 50, 80, 50 }, 100); // ���� : 3
    cout << solution({ 70, 80, 50 }, 100); // ���� : 3
}
#endif