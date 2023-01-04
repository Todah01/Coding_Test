#if 0
#include <string>
#include <vector>
#include<iostream>
#include<cmath>

using namespace std;

int getMyDivisor(int num)
{
    int divisorCount = 0;

    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            divisorCount++;
            if (pow(i, 2) != num)
                divisorCount++;
        }
    }
    return divisorCount;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    int iron_weight = 1;

    for (int number_of_knight = 1; number_of_knight <= number; number_of_knight++)
    {
        int attack = getMyDivisor(number_of_knight);

        if (attack > limit)
            answer += power * iron_weight;
        else
            answer += attack * iron_weight;
    }

    return answer;
}
#endif

#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    col -= 1;
    sort(data.begin(), data.end(), [col](vector<int> a, vector<int> b) {
        return (a[col] != b[col]) ? (a[col] < b[col]) : (a[0] > b[0]);
        });

    for (int t_idx = row_begin; t_idx <= row_end; t_idx++)
    {
        int s_i = 0;
        for (int p_value : data[t_idx - 1])
        {
            s_i += p_value % t_idx;
        }
        answer ^= s_i;
    }
    return answer;
}
#endif