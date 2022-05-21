#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> global_numbers;
int global_target;
int answer;

void dfs(int index, int sum)
{
    if (index == global_numbers.size())
    {
        if (sum == global_target) answer++;
        return;
    }
    dfs(index + 1, sum + global_numbers[index]);
    dfs(index + 1, sum - global_numbers[index]);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    global_numbers = numbers;
    global_target = target;

    dfs(0, 0);
    return answer;
}

int main()
{
    vector<int> numbers = { 1,1,1,1,1 };
    int target = 3;
    cout << solution(numbers, target);
}
#endif