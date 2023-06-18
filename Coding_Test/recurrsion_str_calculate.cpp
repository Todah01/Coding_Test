#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

vector<string> split_string_by_oper(string expression, vector<char> opers) {
    vector<string> tokens;
    stringstream ss(expression);
    string token;

    while (getline(ss, token)) {
        string currentToken;
        for (char c : token) {
            if (find(opers.begin(), opers.end(), c) != opers.end()) {
                if (!currentToken.empty()) {
                    tokens.push_back(currentToken);
                    currentToken = "";
                }
                string oper(1, c);
                tokens.push_back(oper);
            }
            else {
                currentToken += c;
            }
        }
        if (!currentToken.empty()) {
            tokens.push_back(currentToken);
        }
    }

    return tokens;
}

long long cal_string_expression(string a, string b, string oper) {
    if (oper == "+") {
        return stoll(a) + stoll(b);
    }
    else if (oper == "-") {
        return stoll(a) - stoll(b);
    }
    else if (oper == "*") {
        return stoll(a) * stoll(b);
    }
}

long long solution(string expression) {
    long long answer = 0;
    vector<char> symbols = { '*', '+', '-' };
    vector<string> split_expression;

    do {
        split_expression = split_string_by_oper(expression, symbols);
        for (const auto& symbol : symbols) {
            string currentOper(1, symbol);
            while (find(split_expression.begin(), split_expression.end(), currentOper) != split_expression.end()) {
                int idx = distance(split_expression.begin(), find(split_expression.begin(), split_expression.end(), currentOper));
                long long temp_ll = cal_string_expression(split_expression[idx - 1], split_expression[idx + 1], split_expression[idx]);
                split_expression[idx - 1] = to_string(temp_ll);
                split_expression.erase(split_expression.begin() + idx, split_expression.begin() + idx + 2);
            }
        }
        answer = max(answer, abs(stoll(split_expression[0])));
    } while (std::next_permutation(symbols.begin(), symbols.end()));

    return answer;
}
}
#endif