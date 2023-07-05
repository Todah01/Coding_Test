#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<float, long long> weight_map;
    vector<int> dist = { 2, 3, 4 };
    vector<vector<int>> dist_comb;

    for (auto weight : weights) {
        weight_map[weight]++;
    }

    do {
        vector<int> temp;
        for (int i = 0; i < 2; i++) {
            temp.push_back(dist[i]);
        }
        dist_comb.push_back(temp);
    } while (next_permutation(dist.begin(), dist.end()));

    for (auto weight : weights) {
        if (weight_map[weight] > 1) {
            answer += (weight_map[weight] * (weight_map[weight] - 1)) / 2;
        }
        for (auto comb : dist_comb) {
            float check_weight = float((comb[0] * weight)) / float(comb[1]);
            if (weight_map.count(check_weight) > 0) {
                answer += weight_map[weight] * weight_map[check_weight];
            }
        }
        weight_map[weight] = 0;
    }
    return answer;
}
#endif