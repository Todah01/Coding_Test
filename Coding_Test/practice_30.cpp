#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string S){
	bool answer = false;
	if (S.size() == 4 || S.size() == 6)
	{
		for (auto iter : S)
		{
			if (!(iter >= '0' && iter <= '9'))
				answer = false;
			else answer = true;
		}
	}
	return answer;
}

int main() {
	string S = "1234";
	cout << solution(S);
}
#endif