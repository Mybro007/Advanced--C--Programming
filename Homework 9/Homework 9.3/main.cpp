#include<iostream>
#include<memory>

template<class T>

class unique_ptr
{
private:
	T* ptr_;

public:

	unique_ptr() : ptr_(nullptr) {};

	unique_ptr(T* ptr) : ptr_(ptr) {};

	unique_ptr(T& obj) : ptr_(&obj) {};

	unique_ptr(unique_ptr<T>&& uptr) 
	{
		ptr_ = std::move(uptr._ptr);
		uptr.ptr_ = nullptr;
	}

	unique_ptr(const unique_ptr&) = delete;

	~unique_ptr()
	{
		delete ptr_;
	}

	T* release()
	{
		T* answptr = ptr_;
		ptr_ = nullptr;
		return answptr;
	}

	const T& operator *() const
	{
		return *(ptr_);
	}

	T& operator *()
	{
		return *(ptr_);
	}


	T* operator ->()
	{
		return ptr_;
	}

	unique_ptr& operator=(const unique_ptr&) = delete;

};


int main()
{
	int* a = new int(5);
	unique_ptr<int> ptr1(a);
	std::cout << *(ptr1) << "\n";
	return 0;
}