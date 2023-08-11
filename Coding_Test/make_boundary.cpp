#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compareVectors(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    else return a[0] < b[0];
}


int solution(vector<vector<int>> targets) {
    int answer = 0;
    int boundary = 0;
    sort(targets.begin(), targets.end(), compareVectors);

    for (auto target : targets) {
        if (boundary > target[0]) {
            boundary = min(boundary, target[1]);
        }
        else {
            boundary = target[1];
            answer++;
        }
    }

    return answer;
}
#endif