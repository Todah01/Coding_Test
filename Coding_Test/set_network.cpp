#if 0
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> visited;
    queue<int> q;

    for (int cur_node = 0; cur_node < n; cur_node++) {
        if (find(visited.begin(), visited.end(), cur_node) == visited.end()) {
            answer++;
            q.push(cur_node);

            while (!q.empty()) {
                int check_node = q.front();
                q.pop();

                for (int next_node = 0; next_node < n; next_node++) {
                    if (computers[check_node][next_node] == 1 &&
                        find(visited.begin(), visited.end(), next_node) == visited.end()) {
                        visited.push_back(next_node);
                        q.push(next_node);
                    }
                }
            }
        }
    }

    return answer;
}
#endif

#if 0
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int cur_node, int n, vector<int> visited, vector<vector<int>> computers) {
    for (int next_node = 0; next_node < n; next_node++) {
        if (computers[cur_node][next_node] == 1 &&
            find(visited.begin(), visited.end(), next_node) == visited.end()) {
            visited.push_back(next_node);
            dfs(next_node, n, visited, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> visited;
    queue<int> q;

    for (int cur_node = 0; cur_node < n; cur_node++) {
        if (find(visited.begin(), visited.end(), cur_node) == visited.end()) {
            answer++;
            visited.push_back(cur_node);
            dfs(cur_node, n, visited, computers);
        }
    }

    return answer;
}
#endif