#if 1
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int size = citations.size();

    sort(citations.begin(), citations.end());

    for (int i = 0; i < size; i++)
    {
        int h_index = size - i;
        if (citations[i] >= h_index) return h_index;
    }
    return answer;
}

int main()
{
    vector<int> citations = { 3,0,6,1,5 };

    cout << solution(citations);
}
#endif