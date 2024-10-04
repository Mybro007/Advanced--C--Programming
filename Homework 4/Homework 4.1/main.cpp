#include<iostream>
#include<vector>


template<typename T>
T Square(T& num)
{
	return num * num;
}

template<typename T>
std::vector<T> Square(std::vector<T>& vec)
{
	for (int i=0; i<vec.size(); i++)
	{
		vec[i] = vec[i]*vec[i];
	}
	return vec;
}

template<typename V>
std::vector<V> VectorCr(V size)
{
	std::vector<V> vec;
	for (int i=0; i < size; i++)
	{
		V cur{};
		std::cin >> cur;
		vec.push_back(cur);
	}
	return vec;
}

template<typename V>
void VectorPrint(std::vector<V> v)
{
	for (int i=0; i<v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
}

int main()
{
	std::cout << "Choose the object you will input: \n"<<
				"1. Arbitrary number\n"<<
				"2. Sequence of numbers\n";
	unsigned short choose{};
	std::cin >> choose;
	switch (choose)
	{
		case 1:
		{
			std::cout << "Input integer: ";
			int inum{};
			std::cin >> inum;
			std::cout << "Square = " << Square(inum) << "\n";
			std::cout << "Input double: ";
			double dnum{};
			std::cin >> dnum;
			std::cout << "Square = " << Square(dnum) << "\n";
		}
		break;

		case 2:
		{
			std::cout << "Input the size of sequence you want to input: ";
			int size{};
			std::cin >> size;
			std::cout << "Input the type of numbers in sequence \n"<<
						"1. int\n"<<
						"2. double\n";
			unsigned short type{};
			std::cin >> type;
			std::cout << "Input the sequence: ";
			switch (type)
			{
				case 1:
				{
					std::vector<int> vec = VectorCr(size);
					Square(vec);
					std::cout << "Your sequence squared: ";
					VectorPrint(vec);
				}
				break;

				case 2:
				{
					std::vector<double> vec = VectorCr(static_cast<double>(size));
					Square(vec);
					std::cout << "Your sequence squared: ";
					VectorPrint(vec);
				}
				break;

				default:
				{
					std::cout << "Wrong type! Error!\n";
					return -2;
				}
			}
		}
		break;

		default:
		{
			std::cout << "Wrong object! Error!\n";
			return -1;
		}
	}
	return 0;
}