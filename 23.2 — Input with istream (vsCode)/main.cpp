#include <iostream>
#include <iomanip> // for std::setw()
#include <string>

int main()
{
    //The extraction operator:

    char buf[10];
    //setw(), simply provide the maximum number of characters 
    //to read as a parameter, and insert it into your input statement like such
    std::cin >> std::setw(10) >> buf;  
    std::cout << buf << '\n';
    //This program will now only read the first 9 characters out of the stream (leaving room for a terminator). 
    //Any remaining characters will be left in the stream until the next extraction.


    //Extraction and whitespace:
    char ch;
    while(std::cin >> ch)
        std::cout << ch;
    std::cout << std::endl;

    
    //get() function, which simply gets a character from the input stream. Here’s the same program as above using get():
    
    char ch2;
    while(std::cin.get(ch2))
        std::cout << ch2;
    std::cout << std::endl;

    //std::get() also has a string version that takes a maximum number of characters to read:
    char ch3[7];
    std::cin.get(ch3, 7);
    std::cout << ch3 << '\n';

    //getline() that works exactly like get() but reads the newline as well:
    char ch4[11];
    std::cin.getline(ch4, 11);// Read up to 10 characters
    std::cout << ch4 << '\n';

    std::cin.getline(ch4, 11);// Read up to 10 more characters
    std::cout << ch4 << '\n';

    //If you need to know how many character were extracted by the last call of getline(), use gcount():
    char ch5[100];
    std::cin.getline(ch5, 100);
    std::cout << ch5 << '\n';
    std::cout << std::cin.gcount() << " characters were read" << std::endl;

    //A special version of getline() for std::string:
    std::string strBuf;
    std::getline(std::cin, strBuf);
    std::cout << strBuf << '\n';

    //A few more useful istream functions:
    char ch6[10];
    std::cin.ignore(6, 7);
    std::cout << ch6 << '\n';

    return 0;
}