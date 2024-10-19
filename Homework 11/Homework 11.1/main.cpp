#include<iostream>
#include<vector>

template<class T>

void move_vectors(std::vector<T>& v_paste, std::vector<T>& v_copy)
{
	v_paste = std::move(v_copy);
}

int main()
{
	std::vector<std::string> v1{ "Test string 1", "Test string 2", "Test string 3" };
	std::vector<std::string> v2;
	std::cout << "Vector 1: ";
	for (int i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << " ";
	}
	move_vectors(v2, v1);

	std::cout << "\n\nVector 2(moved): ";
	for (int i = 0; i < v2.size(); i++)
	{
		std::cout << v2[i] << " ";
	}
	std::cout << "\n\n";

	return 0;
}