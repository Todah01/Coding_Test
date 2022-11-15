#if 0
#include <string>
#include <iostream>
#include <map>

using namespace std;

int hash_function(string value)
{
	return value.length();
}

int main()
{
	int prices[10];
	string menu_name;

	getline(cin, menu_name);

	prices[hash_function(menu_name)] = 5;

	printf("%s : $%d", menu_name.c_str(), prices[hash_function(menu_name)]);
}
#endif