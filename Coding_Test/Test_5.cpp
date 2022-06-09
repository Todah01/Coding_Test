//1��
#if 0
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    vector<pair<int, int>> divisor;

    for (int i = left; i <= right; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                cnt++;
                if (j != i / j) cnt++;
            }
        }
        divisor.push_back({ i,cnt });
    }

    for (auto& iter : divisor)
    {
        if (iter.second % 2 == 0) answer += iter.first;
        else if (iter.second % 2 == 1) answer -= iter.first;
    }

    return answer;
}
#endif

//2��
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cal_dist(int number, int hand)
{
    vector<vector<int>> dist = { {1,2,3,4}, {2,1,2,3}, {3,2,1,2}, {4,3,2,1}, {0,1,2,3}, {1,0,1,2}, {2,1,0,1}, {3,2,1,0} };

    int cnt = 0;

    if (number == 2) cnt = 0;
    else if (number == 5) cnt = 1;
    else if (number == 8) cnt = 2;
    else if (number == 0) cnt = 3;

    if (hand == 1 || hand == 3) return dist[cnt][0];
    else if (hand == 4 || hand == 6) return dist[cnt][1];
    else if (hand == 7 || hand == 9) return dist[cnt][2];
    else if (hand == 42 || hand == 35) return dist[cnt][3];

    else if (hand == 2) return dist[cnt + 4][0];
    else if (hand == 5) return dist[cnt + 4][1];
    else if (hand == 8) return dist[cnt + 4][2];
    else if (hand == 0) return dist[cnt + 4][3];
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int left_hand = 42;
    int right_hand = 35;

    for (int i = 0; i < numbers.size(); i++)
    {
        //cout << "�޼� ��ġ : " << left_hand << " | " << "������ ��ġ : " << right_hand << " | " << numbers[i] << endl;
        // 1,4,7�� ���� �޼�
        if (numbers[i] % 3 == 1)
        {
            left_hand = numbers[i];
            answer += "L";
        }
        // 3,6,9�� ���� ������
        else if (numbers[i] != 0 && numbers[i] % 3 == 0)
        {
            right_hand = numbers[i];
            answer += "R";
        }
        // 2,5,8,0�� ���� Ű�е��� ��ġ���� �� ����� ��
        else
        {
            // �Ÿ��� ����ϴ� �Լ�
            int l_dist = cal_dist(numbers[i], left_hand);
            int r_dist = cal_dist(numbers[i], right_hand);

            // �Ÿ���
            if (l_dist < r_dist)
            {
                left_hand = numbers[i];
                answer += "L";
            }
            else if (l_dist > r_dist)
            {
                right_hand = numbers[i];
                answer += "R";
            }
            else
            {
                // �Ÿ��� ���� ��� �������� ������ ���� ����
                if (hand == "left")
                {
                    left_hand = numbers[i];
                    answer += "L";
                }
                else if (hand == "right")
                {
                    right_hand = numbers[i];
                    answer += "R";
                }
            }
        }
    }
    return answer;
}
#endif

//3�� - 1
#if 0
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    queue<int> q;

    for (int i = 0; i < progresses.size(); i++) {
        int d = (100 - progresses[i]) / speeds[i];
        if ((progresses[i] + d * speeds[i]) != 100) d++;
        days.push_back(d);
    }

    q.push(days[0]);
    for (int i = 1; i < days.size(); i++) {
        if (q.front() >= days[i]) {
            q.push(days[i]);
        }
        else {
            answer.push_back(q.size());
            while (!q.empty()) q.pop();
            q.push(days[i]);
        }
    }

    if (!q.empty()) answer.push_back(q.size());

    return answer;
}
#endif

//3�� - 2
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    ///vector<int> temp;

    //for(int i=0; i<number.size(); i++) temp.push_back((int)number[i] - '0');


    // � ���� �߿��� k���� ���ڸ� �����ϴ� ��� ����� ���� ����
    long long N = number.size();
    //int N = temp.size();
    long long max = 0;
    vector<int> perm(N);

    for (int i = k; i < N; i++) perm[i] = 1;

    do
    {
        string comb = "";
        for (int i = 0; i < perm.size(); i++)
        {
            // �� ����� ���� ���� ���� �� �ִ� ��� ������ ���� ����
            if (perm[i] == 1) comb += to_string(number[i] - '0');
        }
        if (max < stoll(comb)) max = stoll(comb);
        // cout << comb << endl;
        // cout << "�Ѥ�" << endl;
    } while (next_permutation(perm.begin(), perm.end()));

    answer = to_string(max);

    return answer;
}
#endif