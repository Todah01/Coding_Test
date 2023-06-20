#if 0
#include <string>
#include <vector>
#include <map>
#include <limits>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int bfs(map<int, vector<int>> graph, int start, vector<bool> visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    vector<int> len_vec;

    while (!q.empty()) {
        int edge = q.front();
        len_vec.push_back(edge);
        q.pop();

        for (auto iter : graph[edge]) {
            if (!visited[iter]) {
                q.push(iter);
                visited[iter] = true;
            }
        }
    }

    return len_vec.size();
}

int solution(int n, vector<vector<int>> wires) {
    int answer = numeric_limits<int>::max();

    for (int idx = 0; idx < n - 1; idx++) {
        map<int, vector<int>> graph;
        int edge_cnt = 0;
        set<int> temp_edges;
        vector<vector<int>> temp_wires(wires.begin(), wires.end());
        temp_wires.erase(temp_wires.begin() + idx);

        for (auto wire : temp_wires) {
            int u = wire[0];
            int v = wire[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int j = 1; j < n + 1; j++) {
            vector<bool> visited(n + 1, false);
            edge_cnt = bfs(graph, j, visited);
            temp_edges.insert(edge_cnt);
        }

        auto maxElement = max_element(temp_edges.begin(), temp_edges.end());
        auto minElement = min_element(temp_edges.begin(), temp_edges.end());

        if (*maxElement - *minElement < answer) {
            answer = *maxElement - *minElement;
        }
    }

    return answer;
}
#endif