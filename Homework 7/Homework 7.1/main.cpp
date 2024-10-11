#include<iostream>
#include<fstream>
#include<string>
#include<map>


void get_text(std::string& text);

std::map<char, int> get_map(const std::string& text);

std::multimap<int, char> map_reverse(const std::map<char, int>& text);

void print_answr(const std::multimap<int, char>& rev);


int main()
{
	std::string text;
	get_text(text);
	std::map<char, int> answ = get_map(text);
	std::multimap<int, char> rev = map_reverse(answ);
	print_answr(rev);
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

std::map<char, int> get_map(const std::string& text)
{
	std::map<char, int> answ;

	for (int i = 0; i < text.size(); i++)
	{
		answ[text[i]]++;
	}

	return answ;
}

std::multimap<int, char> map_reverse(const std::map<char, int>& text)
{
	std::multimap<int, char> rev_map;
	for (std::pair<char, int> pr : text)
	{
		std::pair<int, char> rpr;
		rpr.first = pr.second;
		rpr.second = pr.first;
		rev_map.insert(rpr);
	}

	return rev_map;
}

void print_answr(const std::multimap<int, char>& rev)
{
	for (auto it = --(rev.end()); it != --(rev.begin()); --it)
	{
		std::cout << (*it).second << ": " << (*it).first << "\n";
	}
}