#include <iostream>

void errorThrower(int a)
{
    std::string str;
    if (a % 2 == 1)
    {
        std::cout << "throwing 1" << std::endl;
        str = "111";
    }
    else
    {
        std::cout << "throwing 0" << std::endl;
        str = "000";
    }
    throw str;
}

int main()
{
    for (int i = 0; i < 5 ; i++)
    {
        try
        {
            errorThrower(i);
        }
        catch (const std::string & a)
        {
            std::cerr << a << std::endl;
        }
    }
}