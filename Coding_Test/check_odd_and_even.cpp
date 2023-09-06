#if 0
#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int ret = 0;
    int prev = 0;
    for (int station : stations) {
        int a = (station - w - 1) - prev;
        int b = (int)ceil((double)a / (double)(w * 2 + 1));
        ret += max(0, b);
        prev = station + w;
    }
    ret += (int)ceil((double)(n - prev) / (double)(w * 2 + 1));
    return ret;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void fill_arr(vector<int>& arr, int idx, int w) {
    for (int i = idx - w; i <= idx + w; i++) {
        if (i >= 0 && i < arr.size()) arr[i] = 1;
    }
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    vector<pair<int, int>> sect;
    for (int i = 0; i < stations.size(); i++) {
        int s = stations[i] - w > 0 ? stations[i] - w : 1;
        int e = stations[i] + w <= n ? stations[i] + w : n;
        sect.push_back(make_pair(s, e));
    }
    vector<int> arr;
    int prev = 1;
    for (int i = 0; i < sect.size(); i++) {
        if (sect[i].first == 1) {
            prev = sect[i].second + 1;
        }
        else {
            if (sect[i].first - prev > 0)
                arr.push_back(sect[i].first - prev);
            prev = sect[i].second + 1;
        }
    }
    if (prev != n + 1) {
        arr.push_back(n - prev + 1);
    }
    for (int i = 0; i < arr.size(); i++) {
        answer += arr[i] / (2 * w + 1);
        if ((arr[i] % (2 * w + 1))) {
            answer++;
        }
    }


    return answer;
}

#endif