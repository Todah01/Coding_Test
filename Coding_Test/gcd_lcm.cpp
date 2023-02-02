#if 0
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

vector<int> solution(int n, int m) {
    return { gcd(n, m), lcm(n, m) };
}
#endif

#if 0

#endif