#if 0
#include <vector>
#include <cmath>
using namespace std;

int fuc_2(int brown, int yellow)
{
    return ((brown / 2 - 2) + sqrt(pow(2 - brown / 2, 2) - 4 * yellow)) / 2;
}

vector<int> solution(int brown, int yellow) {
    int m, n;
    m = fuc_2(brown, yellow);
    n = yellow / m;
    return { m + 2, n + 2 };
}
#endif

#pragma region Using while
#if 0
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {

    int len = brown / 2 + 2;

    int w = len - 3;
    int h = 3;

    while (w >= h) {
        if (w * h == (brown + red)) break;

        w--;
        h++;
    }

    return vector<int>{w, h};
}
#endif
#pragma endregion
