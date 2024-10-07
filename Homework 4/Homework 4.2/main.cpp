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
			t[i] = new T[cols]{0};
		}
	}

	Table(const Table& t1)
	{
		rows = t1.rows;
		cols = t1.cols;
		t = new T * [rows];
		for (int i = 0; i < rows; i++)
		{
			t[i] = new T[cols]{0};
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				t[i][j] = t1.t[i][j];
			}
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

	Table& operator =(const Table& t1)
	{
		if (&t1 != this)
		{
			for (int i = 0; i < rows; i++)
			{
				delete[] t[i];
			}
			delete[] t;
			rows = t1.rows;
			cols = t1.cols;
			t = new T * [rows];
			for (int i = 0; i < rows; i++)
			{
				t[i] = new T[cols];
			}
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					t[i][j] = t1.t[i][j];
				}
			}
		}
		return *this;
	}
};


int main()
{
	auto test = Table<int>(3, 4);
	Table<int> test1 (2, 1);
	test[0][0] = 4;
	test1 = test;
	std::cout << test[0][0] << "\n";
	std::cout << "Size of the table: " << test.Size() << "\n";
	return 0;
}