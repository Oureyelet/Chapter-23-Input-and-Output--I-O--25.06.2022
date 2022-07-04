#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream inf{ "Sample.txt" };

    if(!inf)// If we couldn't open the input file stream for reading
    {
        // Print an error and exit
        std::cerr << "Ops ! Something wrong...\n";
        return 1;
    }

    std::string strData{};

    inf.seekg(5); // move to 5th character
    // Get the rest of the line and print it
    std::getline(inf, strData);
    std::cout << strData << '\n';

    inf.seekg(8, std::ios::cur); // move 8 more bytes into file
    std::getline(inf, strData);// Get rest of the line and print it
    std::cout << strData << '\n';   

    inf.seekg(-15, std::ios::end);// move 14 bytes before end of file
    std::getline(inf, strData);// Get rest of the line and print it
    std::cout << strData << '\n';

    return 0;
}