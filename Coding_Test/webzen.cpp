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

		// Ȧ�� ����
		if (*it == MASIC_NUMBER)
		{
			// `erase()`�� �ݺ��ڸ� ��ȿȭ�ϰ� ��ȯ�� �ݺ��ڸ� ����մϴ�.
			it = v.erase(it);
			end = v.end();
		}
		// �ݺ��ڴ� else �κп����� �������� �ָ��Ͻʽÿ�(��?)
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