#if 0

2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> series;
    int         tmp;
    int         last;
    double      sum;

    series.push_back(k);
    while (series[series.size() - 1] != 1)
    {
        tmp = series[series.size() - 1];
        if (tmp % 2 == 0)
            series.push_back(tmp / 2);
        else
            series.push_back(tmp * 3 + 1);
    }
    last = series.size() - 1;
    for (int i = 0; i < ranges.size(); i++)
    {
        if (ranges[i][0] > last + ranges[i][1])
        {
            answer.push_back(-1.0);
            continue;
        }
        sum = 0;
        for (int j = ranges[i][0]; j < last + ranges[i][1]; j++)
            sum += (series[j] + series[j + 1]) / 2.0;
        answer.push_back(sum);
    }
    return answer;
}
#endif