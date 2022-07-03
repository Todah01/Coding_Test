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
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

// 시간 변환 함수
int convert_to_m(string line)
{
    string time_h = line.substr(0, 2);
    string time_m = line.substr(3, 2);

    int h = stoi(time_h) * 60;
    int m = stoi(time_m);

    return h + m;
}

//13, 14
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<string, int>> car_enter_list;
    map<string, int> car_exit_list;

    // 요금표 정보를 변수에 담기
    int basic_time = fees[0];
    int basic_fee = fees[1];
    int unit_time = fees[2];
    int unit_fee = fees[3];
    int closing_time = (23 * 60) + 59;

    // 누적 주차 시간계산
    for (auto iter : records)
    {
        // IN 인 경우에는 입차명부에 추가
        if (iter.substr(11, 3) == "IN")
        {
            car_enter_list.push_back({ iter.substr(6,4), convert_to_m(iter) });
        }
        // OUT 인 경우에는 주차시간 계산 후, 출차명부에 추가
        else if (iter.substr(11, 3) == "OUT")
        {
            for (int i = 0; i < car_enter_list.size(); i++)
            {
                if (iter.substr(6, 4) == car_enter_list[i].first)
                {
                    car_exit_list[iter.substr(6, 4)] += convert_to_m(iter) - car_enter_list[i].second;
                    car_enter_list.erase(car_enter_list.begin() + i);
                }
            }
        }
    }

    if (!car_enter_list.empty())
    {
        while (!car_enter_list.empty())
        {
            car_exit_list[car_enter_list.begin()->first] += closing_time - car_enter_list.begin()->second;
            car_enter_list.erase(car_enter_list.begin());
        }
    }

    // for(auto iter : car_exit_list) cout << iter.first << " " << iter.second << endl;

    for (auto iter : car_exit_list)
    {
        if (iter.second > basic_time)
        {
            answer.push_back(basic_fee + (((iter.second - basic_time) + unit_time - 1) / unit_time * unit_fee));
        }
        else answer.push_back(basic_fee);
    }
    return answer;
}
#endif