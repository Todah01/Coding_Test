#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    string s_to_int = "";
    string temp = "";
    // 1. 아스키코드표에서 48이상 57이하인경우 바로 리턴
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 48 && s[i] <= 57) s_to_int += s[i];
        else
        {
            temp += s[i];
            if (temp == "zero")
            {
                s_to_int += "0";
                temp = "";
            }
            else if (temp == "one")
            {
                s_to_int += "1";
                temp = "";
            }
            else if (temp == "two")
            {
                s_to_int += "2";
                temp = "";
            }
            else if (temp == "three")
            {
                s_to_int += "3";
                temp = "";
            }
            else if (temp == "four")
            {
                s_to_int += "4";
                temp = "";
            }
            else if (temp == "five")
            {
                s_to_int += "5";
                temp = "";
            }
            else if (temp == "six")
            {
                s_to_int += "6";
                temp = "";
            }
            else if (temp == "seven")
            {
                s_to_int += "7";
                temp = "";
            }
            else if (temp == "eight")
            {
                s_to_int += "8";
                temp = "";
            }
            else if (temp == "nine")
            {
                s_to_int += "9";
                temp = "";
            }
        }
    }

    int answer = stoi(s_to_int);

    return answer;
}
#endif