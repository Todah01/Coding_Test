//1��
#if 0
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    for (char& ch : new_id) if ('A' <= ch && ch <= 'Z') ch |= 32;

    string ret;
    for (char& ch : new_id) {
        if ('a' <= ch && ch <= 'z' ||
            '0' <= ch && ch <= '9' ||
            strchr("-_.", ch)) ret += ch;
    }

    new_id = ret;
    ret.clear();
    for (char& ch : new_id) {
        if (!ret.empty() && ret.back() == '.' && ch == '.') continue;
        ret += ch;
    }

    if (ret.front() == '.') ret.erase(ret.begin());
    if (ret.back() == '.') ret.pop_back();

    if (ret.empty()) ret = "a";
    if (ret.size() >= 16) ret = ret.substr(0, 15);
    if (ret.back() == '.') ret.pop_back();
    while (ret.size() <= 2) ret += ret.back();

    return ret;
}
#endif

//2��
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//�߿��� ��
//���ڿ��� 100���ڰ� �ִ�, �ٵ� ��� �� ������ ���, int�� �ϰ� �Ǹ� �����÷ο찡 �߻��� �� ����.
//���ڿ��� �ѱ��ھ� ������� ��. �װ� 16~20��° ��.

bool compare(vector<string> a, vector<string> b) {
    if (a[0] == b[0]) {
        if (a[1].size() == b[1].size()) {
            int idx = 0;
            while (a[1].size() != idx) {
                if (a[1][idx] != b[1][idx])
                    return a[1][idx] < b[1][idx];
                idx++;
            }
            if (a[1] == b[1])
                return stoi(a[3]) < stoi(b[3]);
        }
        return a[1].size() < b[1].size();
    }
    return a[0] < b[0];
}
vector<string> splitPart(string fileName, int idx_file) {//������ ���� ������� �����ϱ� ����, '������ ���� ����'�� �޾���.
    vector<string> ret;
    string head = "";
    int idx = 0;
    for (int i = 0; i < fileName.size(); i++) {
        if (isdigit(fileName[i])) {
            idx = i;
            break;
        }
        head += fileName[i];
    }
    string number = "";
    for (int i = idx; i < fileName.size(); i++) {
        if (!isdigit(fileName[i])) {
            idx = i;
            break;
        }
        number += fileName[i];
    }

    string tail = fileName.substr(idx, fileName.size() - idx);
    ret.push_back(head);
    ret.push_back(number);
    ret.push_back(tail);
    ret.push_back(to_string(idx_file));
    return ret;
}
void normalize(vector<string>& file) {
    //HEAD�� �ִ� ���ڵ��� ��� �ҹ��ڷ� ����
    transform(file[0].begin(), file[0].end(), file[0].begin(), ::tolower);

    int idx = 0;
    for (int i = 0; i < file[1].size(); i++) {
        if (file[1][i] != '0') {
            idx = i;
            break;
        }
        idx++;
    }
    //NUMBER�� �� �տ� �ִ� 0���� ���ش�.
    file[1] = file[1].substr(idx, file[1].size() - idx);
}
void printInfo(vector<string> file) {
    cout << file[0] << ' ' << file[1] << ' ' << file[2] << endl;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    vector<vector<string>> temp;
    for (int i = 0; i < files.size(); i++) {
        //1.HEAD, NUMBER, TAIL�κ����� ������.
        vector<string> fileInfo = splitPart(files[i], i);
        //printInfo(fileInfo);

        //2.HEAD�� �ִ� �빮�ڵ��� ��� �ҹ��ڷ� �ٲ��ְ�, NUMBER�� �ִ� �ʿ���� 0���� �����ش�.
        normalize(fileInfo);
        //printInfo(fileInfo);

        temp.push_back(fileInfo);
    }
    sort(temp.begin(), temp.end(), compare);

    for (int i = 0; i < temp.size(); i++) {
        int idx_files = stoi(temp[i][3]);
        answer.push_back(files[idx_files]);
    }
    return answer;
}
#endif