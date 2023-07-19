#if 0
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> key_count;
    for (auto key : keymap)
        for (int idx = 0; idx < key.length(); idx++) {
            if (key_count.count(key[idx]) != 0)
                key_count[key[idx]] = min(key_count[key[idx]], idx + 1);
            else
                key_count[key[idx]] = idx + 1;
        }

    for (auto target : targets) {
        int count = 0;
        for (auto part : target) {
            if (key_count[part] == 0) {
                count = -1;
                break;
            }
            else {
                count += key_count[part];
            }
        }
        answer.push_back(count);
    }

    return answer;
}
#endif