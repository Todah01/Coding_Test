#if 0
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

long long factorial(int n) {
    if (n > 1) return n * factorial(n - 1);
    else return 1;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> n_list(n, 0);
    iota(n_list.begin(), n_list.end(), 1);

    while (n > 0) {
        int quotient = (k - 1) / factorial(n - 1);
        if (quotient < 0) quotient = 0;

        answer.push_back(n_list[quotient]);
        n_list.erase(n_list.begin() + quotient);

        k %= factorial(n - 1);
        if (k == 0) k = factorial(n - 1);
        n--;
    }
    return answer;
}
#endif