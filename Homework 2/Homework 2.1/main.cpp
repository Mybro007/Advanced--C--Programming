#include<iostream>

class smart_array
{
private:
	int size{};
	int* arr;
	int index{0};

public:
	smart_array(int size_) : size(size_)
	{
		arr = new int[size];
	}

	void add_element(int elem)
	{
		if (index >= size)
		{
			std::cout<< "Array is already full !!!\n";
		}
		else
		{
			arr[index] = elem;
			index++;
		}
	}

	int get_element(int index1)
	{
		return arr[index1];
	}

	~smart_array()
	{
		delete[] arr;
	}
};



int main()
{
	int size{};
	std::cout << "Input the size of the array: ";
	std::cin >> size;
	{
		smart_array arr(size);
		std::cout << "Input the array (to stop process of inputting: input '-999'): \n";
		int cur_el{};
		std::cout << "Input the element of array: ";
		std::cin >> cur_el;
		while (cur_el != -999)
		{
			arr.add_element(cur_el);
			std::cout << "Input the element of array: ";
			std::cin >> cur_el;
		}

		std::cout << "Your array: ";
		for (int i = 0; i < size; i++)
		{
			std::cout << arr.get_element(i) << " ";
		}
		std::cout << "\n\n";
	}
	return 0;
}