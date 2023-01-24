#if 0
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (n >= a)
    {
        int cola = (n / a) * b;
        answer += cola;
        n = (n % a) + cola;
    }

    return answer;
}
#endif

#pragma region Using back tracking
#if 0
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while (n >= a) {
        answer += b;
        n -= (a - b);
    }
    return answer;
}
#endif
#pragma endregion
