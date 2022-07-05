#include <iostream>
#include <fstream>
#include <string>
#include <istream>

int main()
{
    //The file pointer:

    //Random file access with seekg() and seekp():

    /*
    Random file access is done by manipulating the file pointer using 
    either seekg() function (for input) and seekp() function (for output).
    
    Ios seek flag	Meaning
    beg	            The offset is relative to the beginning of the file (default)
    cur	            The offset is relative to the current location of the file pointer
    end	            The offset is relative to the end of the file
    */

    std::ofstream inf{ "Sample.txt" };

    if(!inf)// If we couldn't open the input file stream for reading
    {
        // Print an error and exit
        std::cerr << "Ops ! Something wrong...\n";
        return 1;
    }


    inf << "This is line 1" << '\n';
    inf << "This is line 2" << '\n';
    inf << "This is line 3" << '\n';
    inf << "This is line 4" << '\n';

    //Go see our seekq() / seekp() / tellg() file cpp please...


    //Reading and writing a file at the same time using fstream:
    //see our std::fstream example.cpp file


    //Other useful file functions:

    std::cout << std::boolalpha << '\n'; // print true of false instead of 1 and 0
    std::cout << inf.is_open() << '\n'; // print true if file is still open

    inf.close(); // close inf file

    std::cout << inf.is_open() << '\n'; // print true if file is still open


    //A warning about writing pointers to disk:

    return 0;
}