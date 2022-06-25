#if 0
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;

    while (answer <= 500)
    {
        if (num == 1) break;
        else if (num % 2 == 0) num /= 2;
        else if (num % 2 == 1)
        {
            num *= 3;
            num += 1;
        }

        if (num == 1)
        {
            answer++;
            break;
        }
        else answer++;
    }

    if (num != 1) answer = -1;

    return answer;
}
#endif