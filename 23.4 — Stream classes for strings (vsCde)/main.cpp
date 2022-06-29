#include <iostream>
#include <sstream> // for stringstreams
#include <string>

int main()
{
    std::stringstream os;
    os << "en grade!" << '\n';// insert "en garde!" into the stringstream

    std::cout << os.str() << '\n';
    
    os.str("en grade!");// set the stringstream buffer to "en garde!"

    //Use the extraction (>>) operator:
    std::stringstream os2;
    os2 << "12 345 67.89";// insert a string of numbers into the stream

    std::string strValue;
    os2 >> strValue;

    std::string strValue2;
    os2 >> strValue2;

    std::string strValue3;
    os2 >> strValue3;

    // print the numbers separated by a dash
    std::cout << strValue << " - " << strValue2 << " - " << strValue3 << '\n';


    //Conversion between strings and numbers:

        //  - First, let’s take a look at converting numbers into a string:
        std::stringstream os5;
        
        int nValue{ 12345 };
        double dValue{ 67.89 };
        os << nValue << ' ' << dValue << '\n';

        std::string strOne, strTwo;
        os >> strOne >> strTwo;

        std::cout << strOne << ' ' << strTwo << '\n';
    
    //Now let’s convert a numerical string to a number:


    return 0;
}