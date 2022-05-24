#if 0
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> map_clothes;

    // 1. 옷의 종류 별 갯수를 체크
    for (auto& clothInfo : clothes)
    {
        map_clothes[clothInfo[1]] += 1;
        //cout << clothInfo[1] << map_clothes[clothInfo[1]] << endl;
    }

    // 2. 옷을 입지 않는 경우를 포함한 모든 경우의 수를 구함.
    // N과 M을 하나씩 선택하는 모든 경우의 수를 구하면 N의갯수*M의갯수의 경우의 수가 나온다.
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