#if 0
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<long long> n_case_list(n + 1, 0);
    n_case_list[2] = 3, n_case_list[4] = 11;
    for (int i = 6; i < n + 1; i += 2) {
        n_case_list[i] = ((n_case_list[i - 2] * 4) % 1000000007 - (n_case_list[i - 4] % 1000000007) + 1000000007) % 1000000007;
    }

    return n_case_list[n] % 1000000007;
}
#endif