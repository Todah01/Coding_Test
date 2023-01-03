#if 0
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0, nFirst = 1, nSecond = 0, nTmp = 0;
    char x = s[0];
    bool bBool = false;

    if (s.size() == 1) {
        return 1;
    }

    for (int i = 1; i < s.size(); i++) {
        s[i] == x ? nFirst++ : nSecond++;
        if (nFirst == nSecond) {
            x = s[i + 1];
            nFirst = 1;
            nSecond = 0;
            answer++;
            i++;
        }

        if (i == s.size() - 1) {
            answer++;
        }
    }
    return answer;
}
#endif