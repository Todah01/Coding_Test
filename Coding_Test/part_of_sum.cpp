#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string t, string p) {
    int answer = 0;

    for (int i = 0; i < t.length() - p.length() + 1; i++)
    {
        if (stol(t.substr(i, p.length())) <= stol(p))
            answer++;
    }

    return answer;
}