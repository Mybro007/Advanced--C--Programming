#include<iostream>

template<class T>
class Table
{
private:
	int rows{ 0 };
	int cols{ 0 };
	T** t;

public:
	Table(int rows_, int cols_) : rows(rows_), cols(cols_)
	{
		t = new T* [rows];
		for (int i = 0; i < rows; i++)
		{
			t[i] = new T [cols];
		}
	}

	int Size() const
	{
		return rows * cols;
	}

	~Table()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] t[i];
		}
		delete[] t;
	}

	T*& operator[](int index) const
	{
		return t[index];
	}

	T* operator[](int index)
	{
		return t[index];
	}
};


int main()
{
	auto test = Table<int>(3, 4);
	test[0][0] = 4;
	std::cout << test[0][0] << "\n";
	std::cout << "Size of the table: " << test.Size() << "\n";
	return 0;
}