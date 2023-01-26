#if 0
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    set<int> check;

    for (int i = 1; i < elements.size() + 1; i++)
        for (int j = 0; j < elements.size(); j++)
        {
            int sum = 0;
            for (int w = 0; w < i; w++)
            {
                if (j + w > elements.size() - 1)
                    sum += elements[j + w - elements.size()];
                else
                    sum += elements[j + w];
            }
            check.insert(sum);
        }

    return check.size();
}
#endif

#pragma region Using %
#if 0
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> S;

    int n = elements.size();

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < i + n; ++j) {
            sum += elements[j % n];
            S.insert(sum);
        }
    }

    return S.size();
}
#endif
#pragma endregion