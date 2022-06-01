#if 0
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    return answer;
}
#endif

#if 0
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    return answer;
}
#endif

#if 0
#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    string base = "AEIOU";
    int num[5] = { 781, 156, 31, 6, 1 };
    for (int i = 0;i < word.size();i++) {
        int idx = base.find(word[i]);
        answer += idx * num[i];
    }
    return answer + word.size();
}
#endif