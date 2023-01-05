#if 0
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> old_bro, young_bro;

    for (int tp : topping)
        young_bro[tp] += 1;

    for (int tp : topping)
    {
        old_bro[tp] += 1;
        young_bro[tp] -= 1;
        if (young_bro[tp] == 0) young_bro.erase(tp);

        if (old_bro.size() == young_bro.size())
            answer++;
    }

    return answer;
}
#endif

#pragma region Using Set
#if 0
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

struct MYSET {
    set<int> base;
    int counter[10001] = { 0 };

    MYSET(vector<int>& topping) {

        for (auto t : topping) {
            counter[t]++;
            base.insert(t);
        }
    }

    void erase(int& num) {
        if (counter[num] >= 1) {
            counter[num]--;
        }
        if (counter[num] == 0) {
            base.erase(num);
        }
    }

    int size() {
        return base.size();
    }
};

int solution(vector<int> topping) {

    int ans = 0;
    int size = topping.size();

    if (topping.size() == 1) {
        return ans;
    }

    set<int> a;
    MYSET baseSet(topping);

    for (int i = 0; i < topping.size(); i++) {
        baseSet.erase(topping[i]);
        a.insert(topping[i]);

        if (baseSet.size() == a.size()) {
            ans++;
        }
    }
    return ans;
}
#endif
#pragma endregion