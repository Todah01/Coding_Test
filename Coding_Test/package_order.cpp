#if 0
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> main, sub;

    for (int idx = order.size(); idx > 0; idx--)
        main.push(idx);

    for (int package : order)
    {
        if (!sub.empty() && sub.top() == package)
        {
            answer++;
            sub.pop();
        }
        else
        {
            if (main.empty())
                break;
            else
            {
                while (!main.empty())
                {
                    if (main.top() == package)
                    {
                        answer++;
                        main.pop();
                        break;
                    }

                    sub.push(main.top());
                    main.pop();
                }
            }
        }
    }

    return answer;
}
#endif

#pragma region Using Short Coding
#if 0
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> st;
    for (int i = 1; i <= order.size(); ++i)
    {
        st.push(i);

        while (!st.empty() && order[answer] == st.top())
        {
            st.pop();
            answer++;
        }
    }


    return answer;
}
#endif
#pragma endregion
