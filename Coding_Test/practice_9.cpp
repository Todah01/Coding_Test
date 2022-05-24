#if 0
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> map_clothes;

    // 1. ���� ���� �� ������ üũ
    for (auto& clothInfo : clothes)
    {
        map_clothes[clothInfo[1]] += 1;
        //cout << clothInfo[1] << map_clothes[clothInfo[1]] << endl;
    }

    // 2. ���� ���� �ʴ� ��츦 ������ ��� ����� ���� ����.
    // N�� M�� �ϳ��� �����ϴ� ��� ����� ���� ���ϸ� N�ǰ���*M�ǰ����� ����� ���� ���´�.
    for (auto& iter : map_clothes)
    {
        //cout << iter.second << endl;
        answer *= (iter.second + 1);
    }

    return --answer;
}

int main()
{
    vector<vector<string>> clothes = { {"hat","headgear"},{"turban","headgear"}, {"sunglasses","eyewear"} };
    cout << solution(clothes);
}
#endif