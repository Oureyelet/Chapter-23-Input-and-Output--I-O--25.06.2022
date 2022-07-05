#include <iostream>
#include <string>
#include <fstream>

int main()
{
    /*
    Two other useful functions are tellg() and tellp(), 
    which return the absolute position of the file pointer. 
    This can be used to determine the size of a file:
    */

    std::ifstream inf{ "Sample.txt" };

    inf.seekg(0, std::ios::end); // move to end of file
    std::cout << inf.tellg() << '\n'; // print 

    return 0;
}