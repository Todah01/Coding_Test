#if 0
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int size = sequence.size();
    int right = 0;
    int partial_sum = sequence[0];

    for (int left = 0; left < size; left++) {
        while (right + 1 < size && partial_sum < k) {
            right++;
            partial_sum += sequence[right];
        }

        if (partial_sum == k) {
            if (answer.empty()) {
                answer = { left, right };
            }
            else {
                int answer_L = answer[0];
                int answer_R = answer[1];
                if (right - left < answer_R - answer_L) {
                    answer = { left, right };
                }
            }
        }

        partial_sum -= sequence[left];
    }

    return answer;
}
#endif