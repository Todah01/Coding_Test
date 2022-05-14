#if 0
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> music;
    map<string, map<int, int>> musiclist;

    for (int i = 0; i < genres.size(); i++)
    {
        music[genres[i]] += plays[i];
        musiclist[genres[i]][i] = plays[i];
    }

    while (music.size() > 0)
    {
        string genre{};
        int max{ 0 };
        //장르 중에서 가장 많이 재생된 장르 찾기
        for (auto mu : music)
        {
            if (max < mu.second)
            {
                max = mu.second;
                genre = mu.first;
            }
        }

        for (int i = 0; i < 2; i++)
        {
            int val = 0, idx = 01;
            //같은 장르의 노래 중에서 가장 많이 재생된 노래 찾기
            for (auto ml : musiclist[genre])
            {
                if (val < ml.second)
                {
                    val = ml.second;
                    idx = ml.first;
                }
            }
            //노래가 1곡 밖에 없다면 반복문 탈출
            if (idx == -1) break;

            //answer에 노래번호 추가
            answer.push_back(idx);
            musiclist[genre].erase(idx);
        }
        music.erase(genre);
    }
    return answer;
}

int main()
{
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500,500,150,800,2500 };
    vector<int> answer;
    vector<int>::iterator iter;

    answer = solution(genres, plays);

    for (iter = answer.begin(); iter != answer.end(); iter++)
    {
        cout << *iter << endl;
    }
}
#endif