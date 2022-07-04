#include <iostream>
#include <fstream>
#include <string>

int main()
{/*
    //File output:
    //go see our "File output.cpp" file

    //File input:
    //go see our "File input.cpp" file

    //Buffered output:

    //File modes:

    
    Ios file mode	    Meaning
    app	                Opens the file in append mode
    ate	                Seeks to the end of the file before reading/writing
    binary	            Opens the file in binary mode (instead of text mode)
    in	                Opens the file in read mode (default for ifstream)
    out	                Opens the file in write mode (default for ofstream)
    trunc	            Erases the file if it already exists
    

    //Let’s write a program that appends two more lines to the Sample.txt file we previously created:
    //go see our "Appends to file(FIle input).cpp" file


    //Using one of the previously sample programs that prints its contents:
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
*/
std::cout << "yo" << '\n';
    return 0;

    // When outf goes out of scope, the ofstream
    // destructor will close the file
}