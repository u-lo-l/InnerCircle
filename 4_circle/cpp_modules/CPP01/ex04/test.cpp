#include <iostream>

int main(int argc, char **argv)
{
	for (int i = 1 ; argv[i] != NULL ; i++)
		std::cout << "->" << argv[i] << std::endl;
}
