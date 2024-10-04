#include <iostream>
#include <vector>

class math_functor
{
private:
	int sum{0};
	int counter{0};
	std::vector<int> v;

public:
	math_functor(std::vector<int> v_) : v(v_)
	{}

	int getSum()
	{
		for (int i = 0; i < v.size(); i++)
		{
			sum += v[i];
		}
		return sum;
	}

	int getCount()
	{
		for (int i = 0; i < v.size(); i++)
		{
			((v[i] % 3 == 0) ? counter++ : counter);
		}
		return counter;
	}

	void operator()()
	{
		std::cout << "Sum = " << getSum() << "\n";
		std::cout << "Quantity of numbers divisible by 3: " << getCount() << "\n";
	}
};


int main()
{
	std::vector<int> v{ 2, 4, 3, 9, 12, 11, -6, 21 };
	math_functor func(v);
	func();
	return 0;
}