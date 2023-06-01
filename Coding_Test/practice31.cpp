# if 1
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> n_stack;

    for (int idx = 0; idx < numbers.size(); idx++) {
        while (!n_stack.empty() && numbers[n_stack.top()] < numbers[idx]) {
            answer[n_stack.top()] = numbers[idx];
            n_stack.pop();
        }

        n_stack.push(idx);
    }

    return answer;
}

int main() {
    vector<int> case_1 = { 2,3,3,5 };
    vector<int> case_2 = { 9,1,5,3,6,2 };
    vector<int> result_1 = { 3,5,5,-1 };
    vector<int> result_2 = { -1,5,6,6,-1,-1 };

    if (solution(case_1) == result_1) {
        cout << "case_1 pass" << endl;
    }
    else {
        cout << "incorrect answer" << endl;
    }

    if (solution(case_2) == result_2) {
        cout << "case_2 pass" << endl;
    }
    else {
        cout << "incorrect answer" << endl;
    }
}
#endif