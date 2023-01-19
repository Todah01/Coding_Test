#if 0
#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    while (n)
    {
        if (n % 2 != 0)
        {
            n--;
            ans++;
        }

        n /= 2;
    }

    return ans;
}
#endif

#pragma region Using Bit
#if 0
#include <iostream>
using namespace std;

int solution_1(int n)
{
    int ans = 0;
    for (int i = 0;i < 31;i++)
        if (n & (1 << i))
            ans++;
    return ans;
}

int solution_2(int n)
{
    return __builtin_popcount(n);
}

int main()
{
    cout << solution_2(6);
}
#endif
#pragma endregion