#if 0
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <numeric>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> temp(n + 1, 1);

    for (int i = 2; i < sqrt(n); i++)
    {
        if (temp[i])
        {
            int j = 2;
            while (i * j <= n)
            {
                temp[i * j] = 0;
                j += 1;
            }
        }
    }

    return accumulate(temp.begin(), temp.end(), 0) - 2;
}
#endif

#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int len = numbers.size();

    vector<bool> v(len - 2, false);
    v.insert(v.end(), 2, true);

    do {
        int temp = 0;
        for (int k = 0; k < len; k++) {
            if (v[k]) temp += numbers[k];
        }
        answer.push_back(temp);
    } while (next_permutation(v.begin(), v.end()));

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}
#endif

#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;

    string ans = "";
    while (n > 0)
    {
        ans += to_string(n % 3);
        n /= 3;
    }
    reverse(ans.begin(), ans.end());

    int idx = 0;
    for (auto iter : ans)
    {
        answer += (iter - '0') * pow(3, idx);
        idx++;
    }

    return answer;
}
#endif