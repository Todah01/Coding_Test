// 1번
#if 0
#include <string>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    return answer;
}

int main()
{
    cout << solution("FRANCE", "french") << endl; // 정답 : 16384
    cout << solution("handshake", "shake hands") << endl; // 정답 : 65536
    cout << solution("aa1+aa2", "AAAA12") << endl; // 정답 : 43690
    cout << solution("E=M*C^2", "e=m*c^2") << endl; // 정답 : 65536
}
#endif

// 2번
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    return answer;
}

int main()
{
    for (auto iter : solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"))
    {
        cout << iter << " "; // 정답 : 2 1 3 4
    }
    cout << endl;

    for (auto iter : solution("{{1,2,3},{2,1},{1,2,4,3},{2}}"))
    {
        cout << iter << " "; // 정답 : 2 1 3 4
    }
    cout << endl;

    for (auto iter : solution("{{20,111},{111}}"))
    {
        cout << iter << " "; // 정답 : 111 20
    }
    cout << endl;

    for (auto iter : solution("{{123}}"))
    {
        cout << iter << " "; // 정답 : 123
    }
    cout << endl;

    for (auto iter : solution("{{4,2,3},{3},{2,3,4,1},{2,3}}"))
    {
        cout << iter << " "; // 정답 : 3 2 4 1
    }
    cout << endl;
}
#endif