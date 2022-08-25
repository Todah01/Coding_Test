// 1번
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<char> x_y_intersection;
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    set_intersection(X.begin(), X.end(), Y.begin(), Y.end(), back_inserter(x_y_intersection));

    sort(x_y_intersection.begin(), x_y_intersection.end(), greater<char>());

    string temp = "";
    for (auto iter : x_y_intersection) temp += iter;

    if (temp == "") answer += "-1";
    else if (stoi(temp) == 0) answer += "0";
    else answer += temp;
    return answer;
}

int main()
{
    cout << solution("100", "2345") << endl; // 정답 : -1
    cout << solution("100", "203045") << endl; // 정답 : 0
    cout << solution("100", "123450") << endl; // 정답 : 10
    cout << solution("12321", "42531") << endl; // 정답 : 321
    cout << solution("5525", "1255") << endl; // 정답 : 552
}
#endif

// 2번
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    queue<int> main;
    stack<int> sub;

    for (int i = 1; i < order.size() + 1; i++) main.push(i);

    for (auto package : order)
    {
        if (!sub.empty() && sub.top() == package)
        {
            sub.pop();
            answer++;
        }
        else
        {
            if (main.empty())
                break;
            else
            {
                while (!main.empty())
                {
                    int main_package = main.front();
                    main.pop();

                    if (main_package == package)
                    {
                        answer++;
                        break;
                    }
                    else
                    {
                        sub.push(main_package);
                    }
                }
            }
        }
    }

    return answer;
}

int main()
{
    cout << solution({ 4, 3, 1, 2, 5 }) << endl; // 정답 : 2
    cout << solution({ 5, 4, 3, 2, 1 }) << endl; // 정답 : 5
}
#endif