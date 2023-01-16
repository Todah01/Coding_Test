#if 0
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    int len = words.size();
    map<string, int> h;
    h[words[0]] = 1;
    for (int i = 1;i < len;i++)
    {
        int len1 = words[i - 1].size();
        if (h[words[i]] || (words[i - 1][len1 - 1] != words[i][0]))
            return { i % n + 1,i / n + 1 };
        else
            h[words[i]] = 1;
    }
    return { 0,0 };
}
#endif

#pragma region Using unordered_set
#if 0
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
vector<int> solution(int n, vector<string> words) {
    unordered_set<string> said_words;                       //O(1)으로 말한 단어인지 체크할 수 있는 컨테이너
    for (int i = 0; i < words.size(); ++i)
        if (!said_words.insert(words[i]).second ||           //이미 말한 단어이거나
            (i > 0 && words[i - 1].back() != words[i].front()))  //앞에서 말한 단어의 끝으로 시작하지 않을 때
            return { i % n + 1,i / n + 1 };                           //탈락자번호와 탈락자가 몇번째로 말한 단어인지 반환
    return { 0,0 };                                           //끝까지 탈락자 발생 안한 경우
}
#endif
#pragma endregion
