//1번
#if 0
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    return answer;
}
#endif

//2번
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> temp_1, temp_2, temp_3;

    //이진수 출력

    for (int i = 0; i < n; i++)
    {
        string temp;

        for (int j = n - 1; j >= 0; --j)
        { //8자리 숫자까지 나타냄
            int result = arr1[i] >> j & 1;
            temp += result + '0';
        }
        temp_1.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        string temp;

        for (int j = n - 1; j >= 0; --j)
        { //8자리 숫자까지 나타냄
            int result = arr2[i] >> j & 1;
            temp += result + '0';
        }
        temp_2.push_back(temp);
    }

    //for(auto iter : temp_2) cout << iter << endl;

    for (int i = 0; i < n; i++)
    {
        string temp;

        for (int j = 0; j < n; j++)
        {
            temp += to_string(temp_1[i][j] - '0' | temp_2[i][j] - '0');
        }
        temp_3.push_back(temp);
    }

    for (auto iter : temp_3) cout << iter << endl;

    for (int i = 0; i < n; i++)
    {
        string temp;

        for (int j = 0; j < n; j++)
        {
            if (temp_3[i][j] == '1') temp += '#';
            else temp += ' ';
        }
        answer.push_back(temp);
    }

    return answer;
}
#endif

//3번
#if 0
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    return answer;
}
#endif