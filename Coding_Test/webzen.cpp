#if 1
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> v = { 1,2,5,3,4 };
	auto it = v.begin();
	auto end = v.end();

	printf("%p\n", &it);
	printf("%p\n", &end);

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
}
#endif