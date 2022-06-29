#include <iostream>
#include <iomanip> // for std::setprecision
#include <ios> // for std::showpoint

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

    /*
    Group	Flag	Meaning
	std::ios::boolalpha	If set, booleans print “true” or “false”. If not set, booleans print 0 or 1

    Manipulator	Meaning
    std::boolalpha	Booleans print “true” or “false”
    std::noboolalpha	Booleans print 0 or 1 (default)
    */
    std::cout << true << ' ' << false << '\n'; // print 1 0

    std::cout.setf(std::ios::boolalpha);
    std::cout << true << ' ' << false << '\n'; // print true false

    std::cout << std::noboolalpha << true << ' ' << false << '\n'; // print 1 0
    std::cout << std::boolalpha << true << ' ' << false << '\n'; // print true false

    /*
    std::ios::showpos	If set, prefix positive numbers with a +
    std::showpos	Prefixes positive numbers with a +
    std::noshowpos	Doesn’t prefix positive numbers with a +
    */
    std::cout << 5 << '\n'; // print 5

    std::cout.setf(std::ios::showpos);
    std::cout << 5 << '\n'; // print +5

    std::cout << std::noshowpos << 5 << '\n'; //print 5
    std::cout << std::showpos << 5 << '\n'; // print +5
    std::cout << std::noshowpos << 5 << '\n'; //print 5

    /*
    std::ios::uppercase	If set, uses upper case letters
    std::uppercase	Uses upper case letters
    std::nouppercase	Uses lower case letters
    */
    std::cout << 12345678.9 << '\n'; // print +1.23457E+07
    
    std::cout.setf(std::ios::uppercase);
    std::cout << 12345678.9 << '\n'; // print +1.23457E+07

    std::cout << std::nouppercase << 12345678.9 << '\n'; //print +1.23457e+07
    std::cout << std::uppercase << 12345678.9 << '\n'; //print +1.23457E+07

    /*
    std::ios::basefield	std::ios::dec	Prints values in decimal (default)
    std::ios::basefield	std::ios::hex	Prints values in hexadecimal
    std::ios::basefield	std::ios::oct	Prints values in octal
    std::ios::basefield	(none)	Prints values according to leading characters of value

    std::dec	Prints values in decimal
    std::hex	Prints values in hexadecimal
    std::oct	Prints values in octal
    */

    std::cout << 27 << '\n'; // print 27

    std::cout.setf(std::ios::dec, std::ios::basefield);
    std::cout << 27 << '\n'; // print 27

    std::cout.setf(std::ios::oct, std::ios::basefield);
    std::cout << 27 << '\n'; // print 33

    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout << 27 << '\n'; // print 1B

    std::cout << std::dec << 27 << '\n'; //print 27
    std::cout << std::oct << 27 << '\n'; //print 33
    std::cout << std::hex << 27 << '\n'; //print 1B


    //Precision, notation, and decimal points:

    /*
    std::ios::floatfield	std::ios::fixed	        Uses decimal notation for floating-point numbers
    std::ios::floatfield	std::ios::scientific	Uses scientific notation for floating-point numbers
    std::ios::floatfield	(none)	                Uses fixed for numbers with few digits, scientific otherwise
    std::ios::floatfield	std::ios::showpoint	    Always show a decimal point and trailing 0’s for floating-point values

    std::fixed	            Use decimal notation for values
    std::scientific	        Use scientific notation for values
    std::showpoint	        Show a decimal point and trailing 0’s for floating-point values
    std::noshowpoint	    Don’t show a decimal point and trailing 0’s for floating-point values
    std::setprecision(int)	Sets the precision of floating-point numbers (defined in the iomanip header)
    
    std::precision()	    Returns the current precision of floating-point numbers
    std::precision(int)	    Sets the precision of floating-point numbers and returns old precision
    */
    std::cout << std::fixed << '\n';
    std::cout << std::setprecision(3) << 123.456 << '\n'; // print 123.456
    std::cout << std::setprecision(4) << 123.456 << '\n'; // print 123.4560
    std::cout << std::setprecision(5) << 123.456 << '\n'; // print 123.45600
    std::cout << std::setprecision(6) << 123.456 << '\n'; // print 123.456000
    std::cout << std::setprecision(7) << 123.456 << '\n'; // print 123.4560000

    std::cout << std::scientific << '\n';
    std::cout << std::setprecision(3) << 123.456 << '\n'; // print 1.235E+02
    std::cout << std::setprecision(4) << 123.456 << '\n'; // print 1.2346E+02
    std::cout << std::setprecision(5) << 123.456 << '\n'; // print 1.23456E+02
    std::cout << std::setprecision(6) << 123.456 << '\n'; // print 1.234560E+02
    std::cout << std::setprecision(7) << 123.456 << '\n'; // print 1.2345600E+02

    //Using the showpoint manipulator or flag, you can make the stream write a decimal point and trailing zeros:
    std::cout << std::showpoint << '\n';
    std::cout << std::setprecision(3) << 123.456 << '\n'; // print 123.
    std::cout << std::setprecision(4) << 123.456 << '\n'; // print 123.4
    std::cout << std::setprecision(5) << 123.456 << '\n'; // print 123.45
    std::cout << std::setprecision(6) << 123.456 << '\n'; // print 123.456
    std::cout << std::setprecision(7) << 123.456 << '\n'; // print 123.4560

    
    //Width, fill characters, and justification:

    /*
    std::ios::adjustfield	std::ios::internal	Left-justifies the sign of the number, and right-justifies the value
    std::ios::adjustfield	std::ios::left	    Left-justifies the sign and value
    std::ios::adjustfield	std::ios::right	    Right-justifies the sign and value (default)
    
    std::internal	    Left-justifies the sign of the number, and right-justifies the value
    std::left	        Left-justifies the sign and value
    std::right	        Right-justifies the sign and value
    std::setfill(char)	Sets the parameter as the fill character (defined in the iomanip header)
    std::setw(int)	    Sets the field width for input and output to the parameter (defined in the iomanip header)
    
    std::fill()	        Returns the current fill character
    std::fill(char)	    Sets the fill character and returns the old fill character
    std::width()	    Returns the current field width
    std::width(int)	    Sets the current field width and returns old field width
    */
    std::cout << std::dec << '\n';
    std::cout << 22 << '\n';

    std::cout << -12345 << '\n'; // print default value with no field width
    std::cout << std::setw(10) << -12345 << '\n';   // print default with field width
    std::cout << std::setw(10) << std::left << -12345 << '\n'; // print left justified
    std::cout << std::setw(10) << std::right << -12345 << '\n'; // print right justified  
    std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internal justified

    //Now, let’s set a fill character and do the same example:
    std::cout.fill('*');
    std::cout << std::setw(10) << -12345 << '\n';   // print default with field width
    std::cout << std::setw(10) << std::left << -12345 << '\n'; // print left justified
    std::cout << std::setw(100) << std::right << -12345 << '\n'; // print right justified  
    std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internal justified

    return 0;
}