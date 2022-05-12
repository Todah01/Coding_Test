//1번
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)

using namespace std;

bool cmp(const string &a, const string &b)
{
	return a + b > b + a;
}

string solution(vector<int> numbers)
{
	string answer = "";
	vector<string> numbers_str;

	for (int i = 0; i < numbers.size(); i++)
	{
		numbers_str.push_back(to_string(numbers[i]));
	}

	sort(numbers_str.begin(), numbers_str.end(), cmp);
	if (numbers_str[0].compare("0") == 0) return "0";

	for (int i = 0; i < numbers_str.size(); i++)
	{
		answer += numbers_str[i];
	}
	return answer;
}

int main()
{
	int n, size;

	while (1)
	{
		printf("숫자를 입력하세요 | 0 - 종료 | 1 - 입력 | : ");
		scanf("%d", &n);
		if (n == 0) break;
		else
		{
			printf("SIZE 입력 : ");
			scanf("%d", &size);
			vector<int> numbers(size);

			for (int i = 0; i < size; i++)
			{
				cin >> numbers[i];
			}
			cout << solution(numbers) << endl;
		}
	}
}
#endif

//2번 - 1
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>

using namespace std;
set<int> number_set;

bool isPrime(int number)
{
	if (number == 0 || number == 1)
		return false;

	for (int i = 2; i < sqrt(number); i++)
	{
		if (number % i == 0)
			return false;
	}

	return true;
}

void Combination(string element, string others)
{
	if (element != "")
		number_set.insert(stoi(element));

	for (int i = 0; i < others.size(); i++)
	{
		//cout << "Combination(" + element + others[i] +","
		//	+ others.substr(0, i) + others.substr(i + 1, others.size()) + ")" << endl;

		Combination(element + others[i], others.substr(0, i) + others.substr(i + 1, others.size()));
	}
}

int solution(string numbers)
{
	Combination("", numbers);

	int answer = 0;
	//for (set<int>::iterator iter = number_set.begin(); iter != number_set.end(); iter++)
	for(int number : number_set)
		if (isPrime(number))
			answer++;

	return answer;
}

int main()
{
	string numbers;
	cin >> numbers;
	cout << solution(numbers);
}
#endif

//2번 -2
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

bool isPrime(int number)
{
	if (number == 0 || number == 1)
		return false;

	for (int i = 2; i < sqrt(number); i++)
	{
		if (number % i == 0)
			return false;
	}

	return true;
}

int solution(string numbers)
{
	int answer = 0;
	vector<char> numbers_char;
	vector<int> numbers_set;

	for (int i = 0; i < numbers.length(); i++)
	{
		numbers_char.push_back(numbers[i]);
	}

	sort(numbers_char.begin(), numbers_char.end());

	do {
		string temp = "";
		for (int i = 0; i < numbers_char.size(); i++)
		{
			temp.push_back(numbers_char[i]);
			numbers_set.push_back(stoi(temp));
		}
	} while (next_permutation(numbers_char.begin(), numbers_char.end()));

	sort(numbers_set.begin(), numbers_set.end());
	numbers_set.erase(unique(numbers_set.begin(), numbers_set.end()), numbers_set.end());

	for (int i = 0; i < numbers_set.size(); i++)
	{
		if (isPrime(numbers_set[i]))
			answer++;
	}

	return answer;
}

int main()
{
	string numbers;
	cin >> numbers;
	cout << solution(numbers);
}
#endif