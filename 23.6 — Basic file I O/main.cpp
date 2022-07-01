#include <iostream>
#include <fstream>
#include <string>

int main()
{/*
    //File output:

    std::ofstream outf{ "Sample.txt" };// ofstream is used for writing files. We'll make a file called Sample.txt

    if(!outf)// If we couldn't open the output file stream for writing
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
        return 1;
    }

    // We'll write two lines into this file
    outf << "This is line 1" << '\n';
    outf << "This is line 2" << '\n';
*/

    //File input:

    std::ifstream inf{ "Sample.txt" }; // ifstream is used for reading files. We'll read from a file called Sample.txt

    if(!inf)// If we couldn't open the output file stream for reading
    {
        //Print an error and exit
        std::cerr << "Uh oh, Sample.txtcould not be opened for reading!\n";
        return 1;
    }

    while(inf)// While there's still stuff left to read
    {
        std::string strInput{};
        std::getline(inf, strInput);
        std::cout << strInput << '\n';
    }


    //Buffered output:

    //File modes:

    

    return 0;

    // When outf goes out of scope, the ofstream
    // destructor will close the file
}