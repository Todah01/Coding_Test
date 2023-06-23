#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<vector<int>> create_graph(vector<vector<int>> data, int n) {
    vector<int> temp_graph(n + 1, 500001);
    vector<vector<int>> graph(n + 1, temp_graph);

    for (int i = 0; i < n + 1; i++)
        graph[i][i] = 0;

    for (auto iter : data) {
        graph[iter[0]][iter[1]] = min(graph[iter[0]][iter[1]], iter[2]);
        graph[iter[1]][iter[0]] = min(graph[iter[1]][iter[0]], iter[2]);
    }

    return graph;
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<int>> graph;
    graph = create_graph(road, N);

    for (int k = 1; k < N + 1; k++) {
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
            }
        }
    }

    for (auto iter : graph[1]) {
        if (iter <= K) answer++;
    }

    return answer;
}
#endif

// DFS VER.
#if 0
#include <iostream>
#include <vector>

using namespace std;

int     hour[51][51] = { 0, };
bool    possible[51] = { 0, };

void    recurs(int before, int t, int K, bool* visit)
{
    if (t > K)
        return;
    possible[before] = true;
    for (int i = 2; i < 51; i++)
    {
        if (!visit[i] && hour[before][i])
        {
            visit[i] = true;
            recurs(i, t + hour[before][i], K, visit);
            visit[i] = false;
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for (int i = 0; i < road.size(); i++)
    {
        int a = road[i][0], b = road[i][1], t = road[i][2];
        if (t < hour[a][b] || hour[a][b] == 0)
        {
            hour[a][b] = t;
            hour[b][a] = t;
        }
    }
    bool    visit[51] = { 0, };
    visit[1] = true;
    recurs(1, 0, K, visit);
    for (int i = 1; i < 51; i++)
    {
        if (possible[i] == true)
            answer++;
    }

    return answer;
}
#endif