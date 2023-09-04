#if 0
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    priority_queue<int> a_heap(A.begin(), A.end());
    priority_queue<int> b_heap(B.begin(), B.end());

    while (!a_heap.empty()) {
        if (a_heap.top() < b_heap.top()) {
            answer++;
            a_heap.pop();
            b_heap.pop();
        }
        else {
            a_heap.pop();
        }
    }

    return answer;
}
#endif