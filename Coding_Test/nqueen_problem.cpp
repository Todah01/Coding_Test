#if 0
// ������ ����Ǿ����ϴ�. �̷� ���� �Լ� �����̳� �׽�Ʈ���̽��� ����Ǿ�, ������ �ڵ�� �������� ���� �� �ֽ��ϴ�.
// ���ο� �Լ� ������ �����Ϸ��� [�ڵ� �ʱ�ȭ] ��ư�� ��������. ��, [�ڵ� �ʱ�ȭ] ��ư�� ������ �ۼ� ���� �ڵ�� ������ϴ�.
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
    // �Ʒ��� �׽�Ʈ�� ����� ���� ���� �ڵ��Դϴ�.
    cout << nQueen(test);
}

#endif