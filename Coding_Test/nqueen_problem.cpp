#if 0
// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int n;
//vector<bool> c, d1, d2;
bool c[50], d1[100], d2[100];
ll ans;

void dfs(int x, int cnt) {
    if (!cnt) {
        ans++;
        return;
    }
    for (int y = 0; y < n; y++) {
        if (c[y] || d1[x + y] || d2[n - y + x - 1]) continue;
        c[y] = d1[x + y] = d2[n - y + x - 1] = 1;
        dfs(x + 1, cnt - 1);
        c[y] = d1[x + y] = d2[n - y + x - 1] = 0;
    }
}

ll nQueen(int t)
{
    n = t;
    //c.resize(t, false); d1.resize(2 * t - 1, false); d2.resize(2 * t - 1, false);
    for (int y = 0; y < t / 2; y++) {
        c[y] = d1[y] = d2[n - y - 1] = 1;
        dfs(1, n - 1);
        c[y] = d1[y] = d2[n - y - 1] = 0;
    }
    ans *= 2;
    if (n % 2) {
        int y = t / 2;
        c[y] = d1[y] = d2[n - y - 1] = 1;
        dfs(1, n - 1);
        c[y] = d1[y] = d2[n - y - 1] = 0;
    }
    return ans;
}

int main()
{
    int test = 14;
    // 아래는 테스트로 출력해 보기 위한 코드입니다.
    cout << nQueen(test);
}

#endif