#pragma warning( disable : 6386 )
#include<iostream>

template<class T>
class MyVector
{
private:
	T* arr;
	size_t size_{ 0 };
	size_t capacity_{ 0 };

public:
	MyVector() : arr(new T[1]), size_(0), capacity_(1)
	{}

	size_t capacity()
	{
		return capacity_;
	}

	size_t size()
	{
		return size_;
	}

	const T& at(int index) const
	{
		if (index >= size_) throw std::out_of_range("Invalid index");
		return arr[index];
	}

	T& at(int index)
	{
		if (index >= size_) throw std::out_of_range("Invalid index");
		return arr[index];
	}

	void push_back(T obj)
	{
		if (size_ + 1 > capacity_)
		{
			capacity_ *= 2;
			T* arr1 = new T[capacity_];
			for (size_t i = 0; i < size_; i++)
			{
				arr1[i] = arr[i];
			}
			delete[] arr;
			arr = arr1;
		}
		
		size_++;
		arr[size_ - 1] = obj;
	}

	T& operator[](int index)
	{
		return arr[index];
	}
};


int main()
{
	MyVector<int> v1;
	for (int i = 0; i < 100; i++)
	{
		v1.push_back(i+1);
	}
	v1[52] = 999;
	std::cout << "Size of vector is: " << v1.size() << "\n";				//must print 100
	std::cout << "The second element is: " << v1.at(1) << "\n";				//must print 2
	std::cout << "Capacity of vector is: " << v1.capacity() << "\n";		//must print 128
	std::cout << "The 52-nd element is: " << v1[52] << "\n";				//must print 999
	return 0;
}