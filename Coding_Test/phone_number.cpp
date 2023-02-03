#if 0
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    for (int i = 0; i < phone_number.length() - 4; i++) answer += '*';
    answer += phone_number.substr(phone_number.length() - 4, 4);
    return answer;
}
#endif

#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    sort(arr.begin(), arr.end());
    for (int iter : arr) iter% divisor == 0 ? answer.push_back(iter), answer : answer;
    return answer.empty() ? answer.push_back(-1), answer : answer;
}
#endif

#if 0
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    for (int i = 2; i < n;++i)
        if (n % i == 1) return i;
    return n - 1;
}
#endif