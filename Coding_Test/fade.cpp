#if 0
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> clothes_map;

    for (auto clothe : clothes)
    {
        clothes_map[clothe[1]] += 1;
    }
    cout << clothes_map.size();

    for (auto iter : clothes_map)
    {
        answer *= iter.second + 1;
    }

    return --answer;
}
#endif