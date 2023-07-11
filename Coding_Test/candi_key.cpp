#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

vector<vector<int>> get_subset(vector<int> iterable) {
    vector<vector<int>> result;
    int len = iterable.size();

    for (int i = 1; i < len + 1; i++) {
        vector<bool> v(len - i, false);
        v.insert(v.end(), i, true);
        do {
            vector<int> temp;
            for (int k = 0; k < len; k++) {
                if (v[k]) temp.push_back(iterable[k]);
            }
            result.push_back(temp);
        } while (next_permutation(v.begin(), v.end()));
    }

    return result;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int row = relation.size(), col = relation[0].size();

    vector<int> attribute_cnt;
    for (int i = 0; i < col; i++)
        attribute_cnt.push_back(i);

    vector<vector<int>> sub_list = get_subset(attribute_cnt);
    vector<vector<int>> uniq_list;

    for (auto sub : sub_list) {
        bool unique = true;
        set<string> key_set;
        for (int i = 0; i < row; i++) {
            string key = "";
            for (auto j : sub)
                key += relation[i][j];
            if (key_set.find(key) != key_set.end()) {
                unique = false;
                break;
            }
            key_set.insert(key);
        }
        if (unique)
            uniq_list.push_back(sub);
    }

    reverse(uniq_list.begin(), uniq_list.end());

    for (int i = 0; i < uniq_list.size(); i++) {
        bool unique = true;
        for (int j = i + 1; j < uniq_list.size(); j++) {
            if (includes(uniq_list[i].begin(), uniq_list[i].end(), uniq_list[j].begin(), uniq_list[j].end())) {
                unique = false;
                break;
            }
        }

        if (unique) answer++;
    }

    return answer;
}
#endif