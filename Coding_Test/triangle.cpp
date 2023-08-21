#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> dp;
    for (auto iter : triangle) {
        vector<int> temp;
        for (auto value : iter) {
            temp.push_back(0);
        }
        dp.push_back(temp);
    }

    dp[0][0] = triangle[0][0];

    for (int i = 0; i < triangle.size(); i++) {
        for (int j = 0; j < i; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + triangle[i][j]);
            dp[i][j + 1] = dp[i - 1][j] + triangle[i][j + 1];
        }
    }

    return *max_element(dp.back().begin(), dp.back().end());
}
#endif