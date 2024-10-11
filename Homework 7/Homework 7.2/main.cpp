#include<iostream>
#include<set>




int main()
{
	int size{};
	std::set<int> seq;
	std::cout << "Input the size of sequence: ";
	std::cin >> size;
	std::cout << "Input the sequence: \n";
	for (int i = 0; i < size; i++)
	{
		int cur{};
		std::cin >> cur;
		seq.insert(cur);
	}

	std::cout << "\n\nOut: \n";
	for (auto it = --(seq.end()); it != --(seq.begin()); --it)
	{
		std::cout << (*it) << "\n";
	}

	return 0;
}