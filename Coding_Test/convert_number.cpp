#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string convert_to_alphabet(int number, int n)
{
    vector<string> hex_alphabet = { "A", "B", "C", "D", "E", "F" };

    if (number >= 10 && number < n)
        return hex_alphabet[number % 10];

    if (number >= 10)
    {
        number %= 10;
        return hex_alphabet[number];
    }
    else
        return to_string(number);
}

string convert_number(int number, int convert)
{
    if (number == 0)
        return "0";

    string ans = "";

    while (number > 0) {
        ans += convert_to_alphabet(number % convert, convert);
        number /= convert;
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp_str = "";
    int cnt = 0;
    int num_cnt = 0;

    while (cnt < t)
    {
        cnt++;
        while (temp_str.length() < p)
        {
            temp_str += convert_number(num_cnt, n);
            num_cnt++;
            if (temp_str.length() >= p)
                break;
        }

        answer += temp_str[p - 1];
        p += m;
    }

    return answer;
}
#endif

#pragma region Using at
// https://hoho325.tistory.com/318
// 특정 위치의 문자를 가져옴.
#if 0
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

char number[18] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                   'A', 'B', 'C', 'D', 'E', 'F' };

string number_to_n(int num, int n) {
    string result;
    if (num == 0) {
        return "0";
    }
    while (num > 0) {
        result += number[num % n];
        num /= n;
    }
    reverse(result.begin(), result.end());
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp;
    int mt = m * t;
    for (int num = 0; temp.size() <= mt; num++) {
        string ngame = number_to_n(num, n);
        temp += ngame;
    }

    for (int i = 0; i < t; i++) {
        answer += temp.at((m * i) + (p - 1));
    }

    return answer;
}
#endif
#pragma endregion
