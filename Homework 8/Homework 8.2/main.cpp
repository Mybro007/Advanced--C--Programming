#include<iostream>
#include<vector>
#include<set>
#include<list>

template<class T>
void print_container(const T& cont)
{
	for (auto it = cont.begin(); it != cont.end(); ++it)
	{
		std::cout << (*it) << " ";
	}
}

int main()
{
	std::vector<std::string> vec = { "Pig", "Frog", "Cow", "Dog" };
	std::cout << "Vector is: ";
	print_container(vec);
	std::cout << "\n\n";
	std::set<char> st = { 'A', 'B', 'C', 'D' };
	std::cout << "Set is: ";
	print_container(st);
	std::cout << "\n\n";
	std::list<double> l = { 1.543, 3.897, 0.8765, 9.778 };
	std::cout << "List is: ";
	print_container(l);
	std::cout << "\n\n";
	return 0;
}