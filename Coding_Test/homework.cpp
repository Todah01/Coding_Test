#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <iostream>

using namespace std;

bool comp(vector<string> a, vector<string> b) {
    return a[1] < b[1];
}

int getTime(string s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3));
    return h * 60 + m;
}

vector<string> solution(vector<vector<string>> plans) {
    sort(plans.begin(), plans.end(), comp);


    unordered_map<string, int> m;
    for (vector<string> plan : plans) m[plan[0]] = stoi(plan[2]);

    stack<vector<string>> st;
    st.push(plans[0]);

    int idx = 1;
    int time = getTime(plans[0][1]);

    vector<string> answer;
    while (!st.empty()) {
        time++;
        string sub = st.top()[0];
        m[sub]--;

        if (m[sub] == 0) {
            st.pop();
            answer.push_back(sub);
        }

        if (idx < plans.size() && (time == getTime(plans[idx][1]) || st.empty())) {
            st.push(plans[idx]);
            time = getTime(plans[idx][1]);
            idx++;
        }
    }
    return answer;
}
#endif