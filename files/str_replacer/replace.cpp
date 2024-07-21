#include <string>
#include <iostream>
#include <fstream>

// ofstream: Stream class to write on files
// ifstream: Stream class to read from files
// fstream: Stream class to both read and write from/to file

// uses find, erase and insert
std::string	strReplace(std::string str, std::string s1, std::string s2)
{
	std::size_t	found;

	while (1) {
		found = str.find(s1);
		if (found == std::string::npos)
			return (str);
		str.erase(found, s1.length());
		str.insert(found, s2);
	}
}

void	replace(const char *filename, std::string newfile, std::string s1, std::string s2)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	// std::string		newfile;
	std::string		line;

	infile.open(filename);
	if (!infile.is_open()) {
		std::cout << "Error: File not found\n";
		return ;
	}

	outfile.open(newfile.c_str());
	while (1) {
		if (getline(infile, line)) {
			outfile << strReplace(line, s1, s2) << std::endl;
		}
		else
			break ;
	}
	infile.close();
	outfile.close();
}

void	to_upper(std::string& str) {
	for (int i = 0; i < str.length(); i++) {
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] -= 32;
	}
}

// ---------------------------------------------------------------------------

int	main(int argc, char *argv[]) {
	if (argc != 3)
		return (1);

	std::string	classname = std::string(argv[2]);
	std::string	newfile = std::string(argv[1]);
	std::size_t	found;

	// argv[1] is newfile, argv[2] is classname
	// if argv[1] ends .cpp only do classname
	// if argv[1] ends .hpp do classname and include guard in all caps

	found = newfile.find(".cpp");
	if (found != std::string::npos) {
		std::cout << "replacing .cpp file...\n";
		replace("AClass.cpp", newfile, "AClass", classname);
	}
	found = newfile.find(".hpp");
	if (found != std::string::npos) {
		std::cout << "replacing .hpp file...\n";
		replace("AClass.hpp", "header", "AClass", classname);
		to_upper(classname);
		replace("header", newfile, "ACLASS", classname);
	}
}
