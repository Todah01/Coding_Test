#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string tolower(string str)
{
    for (int i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);

    return str;
}

bool cmp(vector<string> a, vector<string> b)
{
    if (tolower(a[0]) == tolower(b[0]))
    {
        if (stoi(a[1]) != stoi(b[1]))
            return stoi(a[1]) < stoi(b[1]);
    }
    else
    {
        return tolower(a[0]) < tolower(b[0]);
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<vector<string>> split_files;

    for (auto file : files)
    {
        vector<string> temp_files;
        bool is_tail = false;
        bool is_number = false;
        string temp_str = "";

        for (char iter : file)
        {
            if (iter >= '0' && iter <= '9')
            {
                // 처음으로 숫자가 나왔을 경우
                if (is_tail)
                {
                    if (temp_str.length() + 1 > 5)
                    {
                        temp_files.push_back(temp_str);
                        temp_str = iter;
                        is_tail = false;
                        is_number = true;
                    }
                    else
                    {
                        temp_str += iter;
                    }
                }
                else
                {
                    if (is_number)
                    {
                        temp_str += iter;
                    }
                    else
                    {
                        temp_files.push_back(temp_str);
                        temp_str = iter;
                        is_tail = true;
                    }
                }
            }
            else
            {
                if (is_tail)
                {
                    temp_files.push_back(temp_str);
                    temp_str = iter;
                    is_tail = false;
                    is_number = true;
                }
                else
                {
                    temp_str += iter;
                }
            }
        }
        temp_files.push_back(temp_str);
        split_files.push_back(temp_files);
    }

    stable_sort(split_files.begin(), split_files.end(), cmp);

    for (auto iter : split_files)
    {
        string temp = "";
        for (auto str : iter)
            temp += str;

        answer.push_back(temp);
    }

    return answer;
}
#endif

#pragma region Using class
#if 0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class File {
public:
    string h;
    int n;
    string t;
    File(string _h, int _n, string _t) : h(_h), n(_n), t(_t) {}
};

vector<File> file;

bool cmp(const File& a, const File& b) {
    if (a.h.compare(b.h) == 0) return a.n < b.n;
    else return a.h < b.h;
} // 같거나를 포함해도 여전히 안정성이 없다. stable_sort해 주자

string strupr(string str) {
    for (int i = 0; i <= str.size(); i++)
        if ('a' <= str[i] && str[i] <= 'z')
            str[i] -= 32;
    return str;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    for (int i = 0; i < files.size(); i++) {
        int s = 0;
        for (int j = 0; j < files[i].size(); j++) {
            if ('0' <= files[i][j] && files[i][j] <= '9') {
                s = j;
                break;
            }
        }
        file.push_back(File(strupr(files[i].substr(0, s)), stoi(files[i].substr(s)), files[i]));
    }
    stable_sort(file.begin(), file.end(), cmp);
    for (int i = 0; i < file.size(); i++)
        answer.push_back(file[i].t);
    return answer;
}
#endif
#pragma endregion

#pragma region Using stable_class
#if 0
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
char makeLower(char c)
{
    if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
    return c;
}
int findNumIdx(const string& str)
{
    int i;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            break;
    }
    return i;
}
int getNumber(string str)
{
    return std::stoi(str.substr(findNumIdx(str)));
}
string getHeader(string str)
{
    string rtn = str.substr(0, findNumIdx(str));

    std::transform(rtn.begin(), rtn.end(), rtn.begin(), makeLower);

    return rtn;
}

bool numComp(string str1, string str2) { return getNumber(str1) < getNumber(str2); }
bool headComp(string str1, string str2) { return getHeader(str1).compare(getHeader(str2)) < 0; }

vector<string> solution(vector<string> files)
{
    std::stable_sort(files.begin(), files.end(), numComp);

    std::stable_sort(files.begin(), files.end(), headComp);

    return files;
}
#endif
#pragma endregion
