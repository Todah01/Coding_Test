#if 0
#include <string>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix;

matrix operator* (matrix& a, matrix& b) {
    int a_size = a.size();
    int b_size = b.size();
    int b_length = b[0].size();

    matrix c(a_size, vector<int>(b_length));

    for (int i = 0; i < a_size; i++)
        for (int j = 0; j < b_length; j++)
            for (int k = 0; k < b_size; k++)
                c[i][j] += a[i][k] * b[k][j];

    return c;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    return arr1 * arr2;
}
#endif