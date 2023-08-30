#if 0
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int solution(string begin, string target, vector<string> words) {

    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }

    int answer = 0;
    queue<tuple<string, int>> q;
    vector<bool> visited(words.size(), false);
    q.push(make_tuple(begin, 0));

    while (!q.empty()) {
        vector<int> change_cnt(words.size(), 0);
        string cur_word;
        tie(cur_word, answer) = q.front();
        q.pop();

        if (cur_word == target)
            return answer;

        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words[i].size(); j++)
                if (cur_word[j] == words[i][j])
                    change_cnt[i]++;

        for (int i = 0; i < change_cnt.size(); i++)
            if (change_cnt[i] == target.length() - 1 && !visited[i]) {
                visited[i] = true;
                q.push(make_tuple(words[i], answer + 1));
            }
    }
}
#endif