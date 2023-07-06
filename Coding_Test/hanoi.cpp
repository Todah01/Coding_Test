#if 0
#include <string>
#include <vector>

using namespace std;

void move(int start, int end, vector<vector<int>>& answer) {
    vector<int> temp = { start, end };
    answer.push_back(temp);
}

void hanoi(int N, int start, int end, vector<vector<int>>& answer) {
    if (N == 1) {
        move(start, end, answer);
    }
    else {
        hanoi(N - 1, start, 6 - start - end, answer);
        move(start, end, answer);
        hanoi(N - 1, 6 - start - end, end, answer);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 3, answer);
    return answer;
}
#endif