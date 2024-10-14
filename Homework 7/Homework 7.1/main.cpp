#include<iostream>
#include<fstream>
#include<string>
#include<map>


void get_text(std::string& text);

std::multimap<int, char> get_map(const std::string& text);

void print_answr(const std::multimap<int, char>& rev);


int main()
{
	std::string text;
	get_text(text);
	std::multimap<int, char> answ = get_map(text);
	print_answr(answ);
	return 0;
}



void get_text(std::string& text)
{
	std::ifstream fout("text.txt");
	if (fout.is_open())
	{
		while (!fout.eof())
		{
			getline(fout, text);
		}

		fout.close();
	}
	else
	{
		std::cout << "File with text wasn't found!\n";
		return;
	}
}

std::multimap<int, char> get_map(const std::string& text)
{
	std::map<char, int> m;
	for (int i = 0; i < text.size(); i++)
	{
		m[text[i]]++;
	}

	std::multimap<int, char> answ;

	for (std::pair<char, int> pr : m)
	{
		std::pair<int, char> rpr;
		rpr.first = pr.second;
		rpr.second = pr.first;
		answ.insert(rpr);
	}

	return answ;
}

void print_answr(const std::multimap<int, char>& rev)
{
	for (auto it = --(rev.end()); it != --(rev.begin()); --it)
	{
		std::cout << (*it).second << ": " << (*it).first << "\n";
	}
}