#include <iostream>
#include <fstream>

int main()
{
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


    return 0;
}