// 1번
#if 0
#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

vector<string> slice_string(string str)
{
    vector<string> slice_vector;

    for (int idx = 0; idx < str.length() - 1; idx++)
    {
        string temp = "";
        bool check_correct = true;

        if (isupper(str[idx])) str[idx] = tolower(str[idx]);
        temp += str[idx];

        if (isupper(str[idx + 1])) str[idx + 1] = tolower(str[idx + 1]);
        temp += str[idx + 1];

        for (int temp_idx = 0; temp_idx < temp.length(); temp_idx++)
        {
            if (temp[temp_idx] < 97 || temp[temp_idx] > 122)
                check_correct = false;
        }

        if (check_correct)
            slice_vector.push_back(temp);
    }

    sort(slice_vector.begin(), slice_vector.end());

    return slice_vector;
}

int solution(string str1, string str2) {
    int answer = 0;

    vector<string> slice_str_1 = slice_string(str1);
    vector<string> slice_str_2 = slice_string(str2);
    vector<string> union_str1_and_str2(slice_str_1.size() + slice_str_2.size());
    vector<string> intersection_str1_and_str2(slice_str_1.size() + slice_str_2.size());

    auto union_vector = set_union(slice_str_1.begin(), slice_str_1.end(), slice_str_2.begin(), slice_str_2.end(), union_str1_and_str2.begin());
    union_str1_and_str2.erase(union_vector, union_str1_and_str2.end());

    auto intersection_vector = set_intersection(slice_str_1.begin(), slice_str_1.end(), slice_str_2.begin(), slice_str_2.end(), intersection_str1_and_str2.begin());
    intersection_str1_and_str2.erase(intersection_vector, intersection_str1_and_str2.end());

    //for (auto iter : slice_str_1)
    //    cout << iter << " ";
    //cout << endl;
    //for (auto iter : slice_str_2)
    //    cout << iter << " ";

    if (intersection_str1_and_str2.size() == 0 && union_str1_and_str2.size() != 0)
        return 0;
    else if (intersection_str1_and_str2.size() == 0 && union_str1_and_str2.size() == 0)
        return 65536;
    else
        return (int)(((double)intersection_str1_and_str2.size() / (double)union_str1_and_str2.size()) * 65536);
}

int main()
{
    cout << solution("FRANCE", "french") << endl; // 정답 : 16384
    cout << solution("handshake", "shake hands") << endl; // 정답 : 65536
    cout << solution("aa1+aa2", "AAAA12") << endl; // 정답 : 43690
    cout << solution("E=M*C^2", "e=m*c^2") << endl; // 정답 : 65536
    cout << solution("A+C", "DEF") << endl; // 정답 : 0
}
#endif

// 2번
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    return answer;
}

int main()
{
    for (auto iter : solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"))
    {
        cout << iter << " "; // 정답 : 2 1 3 4
    }
    cout << endl;

    for (auto iter : solution("{{1,2,3},{2,1},{1,2,4,3},{2}}"))
    {
        cout << iter << " "; // 정답 : 2 1 3 4
    }
    cout << endl;

    for (auto iter : solution("{{20,111},{111}}"))
    {
        cout << iter << " "; // 정답 : 111 20
    }
    cout << endl;

    for (auto iter : solution("{{123}}"))
    {
        cout << iter << " "; // 정답 : 123
    }
    cout << endl;

    for (auto iter : solution("{{4,2,3},{3},{2,3,4,1},{2,3}}"))
    {
        cout << iter << " "; // 정답 : 3 2 4 1
    }
    cout << endl;
}
#endif