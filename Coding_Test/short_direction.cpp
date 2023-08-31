#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (auto puddle : puddles) {
        dp[puddle[0] - 1][puddle[1] - 1] = 'X';
    }

    for (int i = 0; i < m; i++) {
        if (dp[0][i] != 'X')
            dp[0][i] = 1;
        else
            break;
    }

    for (int i = 0; i < n; i++) {
        if (dp[i][0] != 'X')
            dp[i][0] = 1;
        else
            break;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (dp[i][j] != 'X' && dp[i][j - 1] == 'X') {
                dp[i][j] = dp[i - 1][j];
            }
            else if (dp[i][j] != 'X' && dp[i - 1][j] == 'X') {
                dp[i][j] = dp[i][j - 1];
            }
            else if (dp[i][j] != 'X') {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[n - 1][m - 1] % 1000000007;
}
#endif