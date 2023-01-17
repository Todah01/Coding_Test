#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int people_size = people.size();
    sort(people.begin(), people.end());
    reverse(people.begin(), people.end());

    for (int i = 0, j = people_size - 1; i <= j; i++)
    {
        if (people[i] + people[j] <= limit)
        {
            j--;
        }
        answer++;
    }

    return answer;
}
#endif

#pragma region Using two pointer
#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int people_size = people.size();
    sort(people.begin(), people.end(), less<>());

    for (int first_p = 0, second_p = people_size - 1; first_p <= second_p; second_p--)
    {
        if (people[first_p] + people[second_p] <= limit)
            first_p++;

        answer++;
    }

    return answer;
}
#endif
#pragma endregion


#if 0
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int solution(vector<int> arr) {
    stack<int> temp;

    for (auto iter : arr)
    {
        if (temp.empty())
        {
            temp.push(iter);
        }
        else
        {
            temp.push(lcm(temp.top(), iter));
        }
    }

    return temp.top();
}
#endif