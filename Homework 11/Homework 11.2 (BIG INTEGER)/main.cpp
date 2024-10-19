#include<iostream>
#include "BigInt.h"


int main()
{
	BigInt big1("114575");
	BigInt big2("78524");
	BigInt big3("81");
	BigInt big4("91");
	BigInt answ1 = big1 + big2;
	BigInt answ2 = big3 * big4;
	std::cout << "Answer of " << big1.get_num() << " + " << big2.get_num() << " is: " << answ1.get_num()  << "\n";
	std::cout << "Answer of " << big3.get_num() << " * " << big4.get_num() << " is: " << answ2.get_num() << "\n";
	return 0;
}