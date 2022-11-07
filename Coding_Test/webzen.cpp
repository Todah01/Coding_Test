#if 0
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> v = { 1,2,5,3,4 };
	auto it = v.begin();
	auto end = v.end();

	int MASIC_NUMBER = 5;

	while (it != end)
	{
		if (*it == MASIC_NUMBER)
		{
			
			v.erase(it++);
		}
		else
		{
			++it;
		}

		for (int idx = 0; idx < v.size(); idx++)
		{
			printf("%d", v[idx]);
		}
		printf("\n");
	}

	vector<int> v = { 1,2,5,3,4 };
	auto it = v.begin();
	auto end = v.end();

	int MASIC_NUMBER = 5;
	int cnt = 0;

	while (it != end)
	{
		cout << cnt << endl;

		// 홀수 제거
		if (*it == MASIC_NUMBER)
		{
			// `erase()`는 반복자를 무효화하고 반환된 반복자를 사용합니다.
			it = v.erase(it);
			end = v.end();
		}
		// 반복자는 else 부분에서만 증가함을 주목하십시오(왜?)
		else {
			++it;
		}

		++cnt;
	}

	for (int const& i : v) {
		std::cout << i << ' ';
	}

	return 0;
}
#endif