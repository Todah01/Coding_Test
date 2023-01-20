#if 0
#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<long long>> matrix;

matrix operator* (matrix& a, matrix& b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
    return c;
}

long long fibonacci(int n)
{
    matrix res = { {1, 0},{0, 1} };
    matrix fib = { {1, 1},{1, 0} };
    while (n) {
        if (n % 2 == 1) res = res * fib;
        fib = fib * fib;
        n *= 0.5;
    }
    return res[0][1];
}

int main()
{
    int testCase = 10;
    long long testAnswer = fibonacci(testCase);

    cout << testAnswer;
}
#endif

#pragma region Using Factorial
#if 0
#include<iostream>
#include<vector>
using namespace std;
long int fac(int n, int k) {
    long int res = 1;
    for (int i = n; i > n - k; i--) { res *= i; }
    return res;
}
int jumpCase(int n)
{
    int a, b;
    long int answer = 0, m;

    for (int i = 0; i <= (int)n / 2; i++) {
        a = n - (i * 2);
        if (a > i) { m = fac(i + a, i) / fac(i, i); }
        else { m = fac(i + a, a) / fac(a, a); }
        // cout<<i<<" "<<"a : "<<a<<", "<< m<<endl;
        answer += m;
    }
    return answer;
}
int main()
{
    int test = 4;

    //아래는 테스트로 출력해 보기 위한 코드입니다.
    cout << jumpCase(test);
}
#endif
#pragma endregion