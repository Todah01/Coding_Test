#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int camera_loc = -30001;

    sort(routes.begin(), routes.end(), compare);

    for (vector<int> route : routes) {
        int start = route[0], end = route[1];
        if (camera_loc < start) {
            camera_loc = end;
            answer++;
        }
        else {
            camera_loc = min(camera_loc, end);
        }
    }
    return answer;
}
#endif