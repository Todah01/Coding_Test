#if 0
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)

using namespace std;

string solution(int n)
{
	string answer = "";
	int rem;
	while (n > 0)
	{
		rem = n % 3;
		n = n / 3;

		if (rem == 0) n -= 1;

		answer += "412"[rem];
	}
	reverse(answer.begin(), answer.end());
	return answer;
}

int main()
{
	
	int n;
	cin >> n;
	cout << solution(n);
}
#endif