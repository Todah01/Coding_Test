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

#endif