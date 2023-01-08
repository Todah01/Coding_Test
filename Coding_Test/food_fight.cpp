#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string temp = "";

    for (int idx = 0; idx < food.size(); idx++)
        for (int cnt = 0; cnt < food[idx] / 2; cnt++)
            temp += to_string(idx);

    answer += temp + "0";
    reverse(temp.begin(), temp.end());
    answer += temp;

    return answer;
}
#endif

#pragma region Using While
#if 0
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "0";
    int check;
    for (int i = food.size() - 1; i > 0; i--) {
        check = food[i] / 2;
        while (check) {
            answer = to_string(i) + answer + to_string(i);
            check--;
        }
    }
    return answer;
}
#endif
#pragma endregion
