#include <iostream>
#include <fstream>

int main()
{
    std::ofstream outf{ "Sample.txt" };// ofstream is used for writing files. We'll make a file called Sample.txt

    if(!outf)// If we couldn't open the output file stream for writing
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
        return 1;
    }

    // We'll write two lines into this file
    outf << "This is our first line :)" << '\n';
    outf << "This is line 2" << '\n';

    


    return 0;
}