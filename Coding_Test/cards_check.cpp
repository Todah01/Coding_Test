#if 0
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int l = 0;
    int r = 0;

    for (string& g : goal) {
        if (g == cards1[l]) {
            l++;
        }
        else if (g == cards2[r]) {
            r++;
        }
        else {
            return "No";
        }
    }

    return "Yes";
}
#endif