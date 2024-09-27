#include<iostream>

class SizeException : std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Array is already full !!!\n";
	}
};

class smart_array
{
private:
	int size{};
	int* arr;
	int index{ 0 };

public:
	smart_array(int size_) : size(size_)
	{
		arr = new int[size];
	}

	smart_array(smart_array& other)
	{
		size = other.size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = other.arr[i];
		}
	}

	void input_arr()
	{
		std::cout << "Input the array (to stop process of inputting: input '-999'): \n";
		int cur_el{};
		std::cout << "Input the element of array: ";
		std::cin >> cur_el;
		while (cur_el != -999)
		{
			add_element(cur_el);
			std::cout << "Input the element of array: ";
			std::cin >> cur_el;
		}
	}

	void print_arr()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << get_element(i) << " ";
		}
		std::cout << "\n\n";
	}

	void add_element(int elem)
	{
		try
		{
			if (index >= size)
			{
				throw SizeException();
			}
			arr[index] = elem;
			index++;
		}
		catch (const SizeException& ex)
		{
			std::cout << ex.what();
		}
	}

	int get_element(int index1)
	{
		return arr[index1];
	}

	smart_array& operator=(const smart_array& other)
	{
		size = other.size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = other.arr[i];
		}
		return *this;
	}

	~smart_array()
	{
		delete[] arr;
	}
};



int main()
{
	int size1{};
	int size2{};
	{
		std::cout << "Input the size of the first array: ";
		std::cin >> size1;
		smart_array arr(size1);
		arr.input_arr();
		std::cout << "The first array: ";
		arr.print_arr();

		std::cout << "Input the size of the second array: ";
		std::cin >> size2;
		smart_array new_arr(size2);
		new_arr.input_arr();
		std::cout << "The second array: ";
		new_arr.print_arr();

		std::cout << "First array after arr1 = arr2: ";
		arr = new_arr;
		arr.print_arr();
	}
	return 0;
}