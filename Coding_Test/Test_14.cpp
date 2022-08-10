// 1번
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int N, int M, vector<vector<int>> city_map) {
    int answer = 0;

    return answer;
}

int main()
{
    vector<vector<int>> city_1 = { {0, 0, 1, 0, 0},
                                   {0, 0, 2, 0, 1},
                                   {0, 1, 2, 0, 0},
                                   {0, 0, 1, 0, 0},
                                   {0, 0, 0, 0, 2},};

    vector<vector<int>> city_2 = { {1, 2, 0, 0, 0},
                                   {1, 2, 0, 0, 0},
                                   {1, 2, 0, 0, 0},
                                   {1, 2, 0, 0, 0},
                                   {1, 2, 0, 0, 0}, };

    vector<vector<int>> city_3 = { {0, 2, 0, 1, 0},
                                   {1, 0, 1, 0, 1},
                                   {0, 0, 0, 0, 0},
                                   {2, 0, 0, 1, 1},
                                   {2, 2, 0, 1, 2}, };

    cout << solution(5, 3, city_1) << endl; // 정답 : 5
    cout << solution(5, 3, city_2) << endl; // 정답 : 11
    cout << solution(5, 3, city_3) << endl; // 정답 : 10
}
#endif

// 2번
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = -1;

    return answer;
}

int main()
{
    cout << solution({ 1, 2, 1, 3, 1, 4, 1, 2 }); // 정답 : 2
    cout << solution({ 1, 2, 3, 1, 4 }); // 정답 : 0
}
#endif

// 3번
#if 0

#endif