#if 1
#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int solution(int x, int y, int n) {
    if (x == y) return 0;

    vector<int> dp(y + 1, INT_MAX);
    dp[x] = 0;

    for (int i = x; i < y; i++) {
        if (dp[i] == INT_MAX)
            continue;

        if (i + n <= y) dp[i + n] = min(dp[i + n], dp[i] + 1);
        if (i * 2 <= y) dp[i * 2] = min(dp[i * 2], dp[i] + 1);
        if (i * 3 <= y) dp[i * 3] = min(dp[i * 3], dp[i] + 1);
    }

    if (dp[y] == INT_MAX) return -1;
    else return dp[y];
}

#endif