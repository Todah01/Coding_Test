#if 0
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> tree;

    for (int i = 0; i < skill.size(); i++) tree.insert({ skill[i], i + 1 });
    // for(auto iter : tree) cout << iter.first << " : " << iter.second << endl;

    for (auto skill_tree : skill_trees)
    {
        int cnt = 1;
        bool check = true;

        for (int i = 0; i < skill_tree.size(); i++)
        {
            if (tree[skill_tree[i]] > cnt)
            {
                // cout << "false " << tree[skill_tree[i]] << " vs " << cnt << " ";
                cnt = 0;
                check = false;
                break;
            }
            else if (tree[skill_tree[i]] > 0)
            {
                // cout << "true " << tree[skill_tree[i]] << " vs " << cnt << " ";
                cnt++;
            }
        }
        cout << endl;

        if (check) answer++;
    }
    return answer;
}
#endif