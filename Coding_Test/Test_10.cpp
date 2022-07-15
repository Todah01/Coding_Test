//1번
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool isCorrect(string p, int* pos)
{
    bool ret = true;
    int left_bracket_cnt = 0;
    int right_bracket_cnt = 0;
    stack<char> check;

    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == '(')
        {
            left_bracket_cnt++;
            check.push(p[i]);
        }
        else
        {
            right_bracket_cnt++;
            if (check.empty()) ret = false;
            else check.pop();
        }

        if (left_bracket_cnt == right_bracket_cnt)
        {
            *pos = i + 1;
            return ret;
        }
    }
}

string solution(string p) {
    string answer = "";
    int pos;
    bool correct = isCorrect(p, &pos);
    string u = "";
    string v = "";

    // 1단계 : 빈 문자열인 경우, 빈 문자열을 반환
    if (correct) return p;

    // 2단계 : u, v를 분리
    for (int i = 0; i < pos; i++) u += p[i];
    for (int i = pos; i < p.size(); i++) v += p[i];

    if (isCorrect(u, &pos))
    {

    }
    return answer;
}
#endif

//2번
#if 0
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp_total(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

bool comp_each(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genre_total_play;
    map<string, vector<pair<int, int>>> genre_each_play;

    for (int i = 0; i < genres.size(); i++)
    {
        genre_total_play[genres[i]] += plays[i];
        genre_each_play[genres[i]].push_back({ i, plays[i] });
    }

    vector<pair<string, int>> temp(genre_total_play.begin(), genre_total_play.end());

    sort(temp.begin(), temp.end(), comp_total);

    // for(auto iter : temp) cout << iter.first << iter.second << endl;
    // for(auto iter : genre_each_play)
    // {
    //     cout << iter.first << endl;
    //     for(auto data : iter.second)
    //     {
    //         cout << data.first << " : " << data.second << endl;
    //     }
    //     cout << endl;
    // }

    for (auto genre : temp)
    {
        sort(genre_each_play[genre.first].begin(), genre_each_play[genre.first].end(), comp_each);
        answer.push_back(genre_each_play[genre.first][0].first);
        if (genre_each_play[genre.first].size() > 1)
            answer.push_back(genre_each_play[genre.first][1].first);
    }

    return answer;
}
#endif