#if 0
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int checking(vector<pair<int, int>>a, vector<vector<string>>& places, int k) {
    for (int i = 0; i < a.size() - 1; i++) {
        for (int j = i + 1; j < a.size(); j++) {
            if (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second) == 2) {
                int maxi = max(a[i].first, a[j].first);
                int mini = min(a[i].first, a[j].first);
                int maxj = max(a[i].second, a[j].second);
                int minj = min(a[i].second, a[j].second);
                int cnt = 0;
                for (int a1 = mini; a1 <= maxi; a1++) {
                    for (int b1 = minj; b1 <= maxj; b1++) {
                        if (places[k][a1][b1] == 'O') {
                            cnt++;

                        }
                    }
                }
                if (cnt != 0) {
                    return 0;
                }
            }
            else if (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second) < 2) {
                return 0;
            }
        }
    }
    return 1;
}

vector<int>solution(vector<vector<string>>places) {
    vector<int>answer;

    for (int i = 0; i < places.size(); i++) {
        vector<pair<int, int>>people;
        for (int j = 0; j < places[i].size(); j++) {
            for (int k = 0; k < places[i][j].size(); k++) {
                if (places[i][j][k] == 'P') {
                    people.push_back(make_pair(j, k));
                }
            }
        }
        if (people.size() == 0) {
            answer.push_back(1);
        }
        else {
            int alpha = checking(people, places, i);
            answer.push_back(alpha);
        }
    }

    return answer;
}
#endif