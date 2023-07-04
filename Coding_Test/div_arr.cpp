#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while (storey > 0) {
        int remainder = storey % 10;
        storey /= 10;

        if (remainder < 5) {
            answer += remainder;
        }
        else if (remainder > 5) {
            answer += 10 - remainder;
            storey += 1;
        }
        else if (remainder == 5) {
            if (storey % 10 < 5) {
                answer += remainder;
            }
            else if (storey % 10 >= 5) {
                answer += 10 - remainder;
                storey += 1;
            }
        }
    }
    return answer;
}
#endif