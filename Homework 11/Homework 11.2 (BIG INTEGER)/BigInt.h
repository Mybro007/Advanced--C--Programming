#pragma once
#include<string>
#include<vector>

class BigInt
{
private:
	std::string numb_;

	std::string add(std::string s1, std::string s2);
	
	std::string trim(std::string s);

	std::string maximum(std::string str1, std::string str2);

	std::string subtract(std::string str1, std::string str2);

	std::string multiply(std::string str1, std::string str2);

public:
	BigInt();

	BigInt(std::string s);
	
	BigInt(unsigned long long n);

	BigInt(const BigInt& other);

	BigInt(BigInt&& other) noexcept;

	std::string get_num();

	BigInt& operator=(const BigInt& other);

	BigInt& operator=(BigInt&& other) noexcept;

	BigInt operator+(const BigInt& other);

	BigInt operator*(const int number);

	BigInt operator *(BigInt const& other);


};