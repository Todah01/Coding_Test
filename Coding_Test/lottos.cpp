#if 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int check_cnt(int n)
{
    if (n == 6) return 1;
    else if (n == 5) return 2;
    else if (n == 4) return 3;
    else if (n == 3) return 4;
    else if (n == 2) return 5;
    else return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int match_cnt = 0;
    int zero_cnt = 0;

    // 0. lottos�� win_nums�� ���ϸ� �� cnt ���
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
        {
            if (lottos[i] != 0 && lottos[i] == win_nums[j])
                match_cnt++;
            else if (lottos[i] == 0)
            {
                zero_cnt++;
                break;
            }
        }

    // 1. 0�� ������ ��ȯ�� �Ŀ� �ְ��� ���
    answer.push_back(check_cnt(match_cnt + zero_cnt));
    // 2. ��ġ�ϴ� ������ ������ ��ȯ�� �Ŀ� ������� ���
    answer.push_back(check_cnt(match_cnt));

    return answer;
}
#endif