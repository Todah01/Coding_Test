#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i < right + 1; i++)
        answer.push_back(max((i % n) + 1, (i / n) + 1));

    return answer;
}
#endif

#pragma region Search decimal number by sieve of Eratosthenes
#if 0
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int number)
{
	if (number == 0 || number == 1)
		return false;

	for (int i = 2; i <= sqrt(number); i++)
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
		numbers_char.push_back(numbers[i]);

	sort(numbers_char.begin(), numbers_char.end());

	do {
		string temp = "";
		for (int i = 0; i < numbers_char.size(); i++)
		{
			temp += numbers_char[i];
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
#endif
#pragma endregion
