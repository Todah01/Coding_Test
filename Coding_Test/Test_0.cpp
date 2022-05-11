//1��
#if 1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const string &a, const string &b)
{
	return a + b > b + a;
}

string solution(vector<int> numbers)
{
	string result = "";
	vector<string> numbers_str;

	//�Է�
	for (int i = 0; i < numbers.size(); i++)
	{
		numbers_str.push_back(to_string(numbers[i]));
	}
	
	//���Ǻ� ����
	sort(numbers_str.begin(), numbers_str.end(), cmp);

	//�� ����
	for (int i = 0; i < numbers_str.size(); i++)
	{
		result += numbers_str[i];
	}

	//����ó��
	if (numbers_str[0].compare("0") == 0) return "0";

	//���
	char* answer = (char*)malloc(sizeof(result));
	answer = (char*)result.c_str();
	return answer;
}

int main()
{
	vector<int> numbers = { 6, 10, 2 };
	
	cout << solution(numbers);
}
#endif

//2��
#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string numbers)
{
	int answer = 0;
	return answer;
}

int main()
{
	//cout << solution();
}
#endif