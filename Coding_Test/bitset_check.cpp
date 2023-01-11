#if 0
#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    int before_s_length = s.length();
    int binary_cnt = 0;
    int remove_zero_cnt = 0;

    while (s != "1")
    {
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        remove_zero_cnt += before_s_length - s.length();

        bitset<32> bit2(s.length());
        s = bit2.to_string();

        if (bit2.any())
            s = s.substr(s.find('1'));
        else
            s = "0";

        before_s_length = s.length();
        binary_cnt++;
    }

    answer.push_back(binary_cnt);
    answer.push_back(remove_zero_cnt);

    return answer;
}
#endif

#pragma region Using emplace
#if 0
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    int zeros{ 0 }, num_transform{ 0 }; vector<bool> bin;
    for_each(s.cbegin(), s.cend(), [&bin](const char c) {bin.emplace_back(c == '1');});  //s를 이진수로 변환
    while (true) {
        if (bin == vector<bool>{true}) break;
        int ones = count(bin.cbegin(), bin.cend(), true);    //1갯수를 셈
        zeros += bin.size() - ones;                          //0갯수를 셈
        bin.clear();
        while (ones > 0) { bin.emplace_back(ones % 2); ones /= 2; }//1갯수를 2진수로 바꿈. 순서는 거꾸로지만 계산에는 영향없음
        ++num_transform;                                   //이진변환 횟수 기록
    }
    return { num_transform,zeros };
}
#endif
#pragma endregion
