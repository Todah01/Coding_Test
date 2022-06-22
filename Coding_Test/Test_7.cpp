//1¹ø
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int comp;

bool cmp(string x, string y)
{
    if (x[comp] == y[comp]) return x <= y;
    return x[comp] < y[comp];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    comp = n;
    sort(strings.begin(), strings.end(), cmp);

    answer = strings;

    return answer;
}
#endif

//2¹ø
#if 0
#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;

    return answer;
}
#endif

//3¹ø
#if 0
#include<vector>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    return answer;
}
#endif