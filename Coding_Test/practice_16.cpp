#if 0
#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

int count_1(int n)
{
    int ret = 0;
    for (int i = 0; i < 31; i++)
        if (n & 0x01 << i)
            ret++;
    return ret;
}

int solution(int n) {
    int answer = count_1(n);

    n++;
    while (1)
    {
        if (answer == count_1(n))
        {
            return n;
        }
        n++;
    }
}
#endif