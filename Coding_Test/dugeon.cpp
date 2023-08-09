#if 0
#include <vector>
#include <iostream>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int visit[100][100];
int max_size_of_one_area = 0;

void dfs(int size, int a, int b, int m, int n, vector<vector<int>> map)
{
    if (map[a][b] == 0 || visit[a][b] == 1) return;

    size++;
    visit[a][b] = 1;
    if (size > max_size_of_one_area) max_size_of_one_area = size;
    cout << size << endl;

    for (int i = 0; i < 4; i++)
    {
        int nx = a + dx[i];
        int ny = b + dy[i];
        if (nx >= 0 && ny >= 0 && nx < m && ny < n)
        {
            dfs(size, nx, ny, m, n, map);
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) visit[i][j] = 0;

    int number_of_area = 0;


    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (picture[i][j] != 0 && visit[i][j] == 0)
            {
                dfs(0, i, j, m, n, picture);
                number_of_area++;
            }
        }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}
#endif