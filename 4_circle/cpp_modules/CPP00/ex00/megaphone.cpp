#include <iostream>
#include <string>
#include <iomanip>
// NO STL(vector map lst ,,,), NO <algorithm>

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		
		for (int i = 1 ; i < argc ; i++)
		{
			std::string str(argv[i]);
			for (unsigned int j = 0; j < str.length(); j++)
				std::cout << char (std::toupper(str[j]));
		}
		std::cout << std::endl;
	}
	return (0);
}
