#include <iostream>

int main()
{
    //The insertion operator:

    //Formatting:

    //C++ does not print a + sign in front of positive numbers. 
    //However, by using the std::ios::showpos flag, we can change this behavior:
    std::cout.setf(std::ios::showpos);// turn on the std::ios::showpos flag
    std::cout << 777 << '\n';

    //It is possible to turn on multiple ios flags at once using the Bitwise OR (|) operator:
    std::cout.setf(std::ios::showpos | std::ios::uppercase);// turn on the std::ios::showpos and std::ios::uppercase flag
    std::cout << 1234567.89f << '\n';

    //To turn a flag off, use the unsetf() function:
    std::cout.setf(std::ios::showpos);// turn on the std::ios::showpos flag
    std::cout << 27 << '\n';
    std::cout.unsetf(std::ios::showpos);// turn off the std::ios::showpos flag
    std::cout << 27 << '\n';

    //we can turn off std::ios::dec so that only std::hex is set:
    std::cout.unsetf(std::ios::dec); // turn off decimal output
    std::cout.setf(std::ios::hex); // turn on hexadecimal output
    std::cout << 77 << '\n';

    // Turn on std::ios::dec as the only std::ios::basefield flag
    std::cout.setf(std::ios::dec, std::ios::basefield);
    std::cout << 22 << '\n';

    /*
    Using setf() and unsetf() tends to be awkward, so C++ provides a second way to change the formatting options: manipulators. 
    The nice thing about manipulators is that they are smart enough to turn on and off the appropriate flags. 
    Here is an example of using some manipulators to change the base:
    */
    std::cout << std::hex << 177 << '\n'; // print 177 in hex
    std::cout << 34 << '\n'; // we're still in hex
    std::cout << std::dec << 88 << '\n'; // back to decimal

    //Useful formatters:

    return 0;
}