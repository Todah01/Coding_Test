#if 1
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_decimal(long num) {
    if (num < 2) return false;
    long a = (long)sqrt(num);
    for (long i = 2; i <= a; i++) if (num % i == 0) return false;
    return true;
}

vector<char> DecToN(int m, int dec) {

    vector<char> result;

    while (true) {

        int i;
        result.push_back((char)(dec % m) + '0');
        dec = dec / m;

        i++;
        if (dec == 0) {
            break;
        }
    }

    return result;
}

int solution(int n, int k) {
    int answer = 0;
    vector<char> number = DecToN(k, n);
    reverse(number.begin(), number.end());

    vector<long> temp_int;
    string temp_str = "";

    for (int i = 0; i < number.size(); i++)
    {
        if (number[i] != '0')
        {
            temp_str += number[i];
        }
        else
        {
            if (temp_str != "")
                temp_int.push_back(stol(temp_str));
            temp_str = "";
        }
    }

    if (temp_str != "")
    {
        temp_int.push_back(stol(temp_str));
    }

    for (auto iter : temp_int)
    {
        if (is_decimal(iter))
            answer++;
    }

    return answer;
}

int main()
{
    cout << solution(437624, 3); // 정답 : 3
    cout << solution(110011, 2); // 정답 : 2
}
#endif