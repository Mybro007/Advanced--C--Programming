#include<iostream>
#include<vector>
#include <algorithm>

template<typename T>
void UniqueVector(std::vector<T>& v)
{
	std::sort(v.begin(), v.end());
	auto it = std::unique(v.begin(), v.end());
	v.erase(it, v.end());
}

int main()
{
	std::vector<int> v = { 1, 1, 2, 5, 6, 1, 2, 4 };
	std::cout << "In: \n";
	for (int i : v)
	{
		std::cout << v[i] << " ";
	}
	UniqueVector(v);
	std::cout << "\n\nOut: \n";
	for (int i=0; i<v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	return 0;
}