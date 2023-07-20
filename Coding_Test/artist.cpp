#if 0
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> photo_score_map;

    for (int idx = 0; idx < name.size(); idx++) {
        photo_score_map[name[idx]] = yearning[idx];
    }

    for (auto art : photo) {
        int count = 0;
        for (auto artist : art) {
            if (photo_score_map[artist] > 0)
                count += photo_score_map[artist];
        }
        answer.push_back(count);
    }

    return answer;
}
#endif