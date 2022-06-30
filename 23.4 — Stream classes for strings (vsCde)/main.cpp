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

        std::cout << strOne << ' ' << strTwo << '\n'; // print 12345 67.89
    
    //Now let’s convert a numerical string to a number:
    std::stringstream os7;
    os << "12345 67.89"; // insert a string of numbers into the stream
    int nValue2;
    double dValue2;

    os >> nValue2 >> dValue2;

    std::cout << nValue2 << ' ' << dValue2 << '\n'; // print 12345 67.89

    //Clearing a stringstream for reuse:
    std::stringstream os8;
    os8 << "Hello ";

    os8.str("");// erase the buffer - Set it to the empty string using str() with a blank C-style string
    os8.str(std::string{}); //Set it to the empty string using str() with a blank std::string object
    os8.clear(); // reset error flags

    os8 << "World!\n";
    std::cout << os8.str();



    return 0;
}