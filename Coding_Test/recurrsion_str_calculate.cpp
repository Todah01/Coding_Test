#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long solution(string expression) {
    vector<long long> result;
    vector<char> symbols = { '*', '+', '-' };
    vector<vector<char>> symbols_perms;
    vector<char> split_expression;

    for (auto iter : expression) split_expression.push_back(iter);

    do {
        vector<char> temp_perm;
        for (const auto& symbol : symbols) {
            temp_perm.push_back(symbol);
        }
        symbols_perms.push_back(temp_perm);
    } while (std::next_permutation(symbols.begin(), symbols.end()));

    for (auto symbols_perm : symbols_perms) {
        for (auto oper : symbols_perm) {
            auto it = find(split_expression.begin(), split_expression.end(), oper);
            if (it != split_expression.end()) {
                int idx = distance(split_expression.begin(), it);
                cout << split_expression[idx];
            }
        }
    }

    return 0;
}
#endif