#if 0
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> temp;

    for (auto iter : nums)
        temp.insert(iter);

    // for(auto iter : temp)
    //     cout << iter << " ";

    if (temp.size() <= nums.size() / 2) answer = temp.size();
    else
    {
        answer = temp.size();
        while (answer > nums.size() / 2)
            answer--;
    }

    return answer;
}
#endif