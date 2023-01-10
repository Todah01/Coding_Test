#if 0
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    stringstream ss(s);
    string stringBuffer;
    vector<int> num;

    while (getline(ss, stringBuffer, ' '))
        num.push_back(stoi(stringBuffer));

    return to_string(*min_element(num.begin(), num.end())) + " " +
        to_string(*max_element(num.begin(), num.end()));;
}
#endif

#if 0
//     transform(s.begin(), s.end(), s.begin(), ::tolower);

//     for(int idx = 0; idx < s.length(); idx++)
//     {
//         if(isalpha(s[idx]))
//         {
//             if(is_space)
//             {
//                 answer += toupper(s[idx]);
//                 is_space = false;
//             }
//             else
//             {
//                 if(idx == 0)
//                     answer += toupper(s[idx]);
//                 else
//                     answer += s[idx];
//             }
//         }
//         else
//         {
//             if(isspace(s[idx]))
//                 is_space = true;
//             answer += s[idx];
//         }
//     }
#endif

#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    int idx = 0;
    bool is_space = true;

    while (s[idx])
    {
        if (isspace(s[idx]))
        {
            is_space = true;
            idx++;
            continue;
        }
        else
        {
            if (is_space)
            {
                s[idx] = toupper(s[idx]);
                is_space = false;
            }
            else
            {
                s[idx] = tolower(s[idx]);
                is_space = false;
            }
            idx++;
        }
    }

    return s;
}
#endif