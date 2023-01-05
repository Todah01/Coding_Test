#if 0
#include <string>
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

int solution(int n, long long l, long long r) {
    int answer = 0;

    vector<bitset<5>> cantor_vector;
    string cantor_number = "1";
    string number_one = "11011";
    string number_zero = "00000";

    bitset<5> bit(number_one);

    for (int i = 0; i < bit.size(); i++)
        if (bit[i] == 1) cout << bit[i];

    int cnt = 1;

    //     while(cnt <= n)
    //     {
    //         string temp_cantor = "";
    //         for(long long idx = 0; idx < cantor.length(); idx++)
    //         {
    //             if(cantor[idx] == '1')
    //                 temp_cantor += number_one;
    //             else
    //                 temp_cantor += number_zero;
    //         }

    //         cantor = temp_cantor;
    //         cnt++;
    //     }

    //     for(long long idx = l - 1; idx < r; idx++)
    //     {
    //         if(cantor[idx] == '1')
    //             answer++;
    //     }

    return answer;
}
#endif