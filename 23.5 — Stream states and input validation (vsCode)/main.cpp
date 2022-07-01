#include <iostream>
#include <algorithm> // std::all_of
#include <cctype> // std::isaplha, std::isspace
#include <string>
#include <string_view>
#include <map>
#include <limits>
#include <optional>
#include <charconv> // std::from_chars

bool isValidName(std::string_view name)
{
    return std::all_of(name.begin(), name.end(), [](char ch){
        return (std::isalpha(ch) || std::isspace(ch));
    });
}

bool inputMatches(std::string_view input, std::string_view pattern)
{
    if(input.length() != pattern.length())
    {
        return false;
    }

    // We have to use a C-style function pointer, because std::isdigit and friends
    // have overloads and would be ambiguous otherwise.
    static const std::map<char, int (*)(int)> validators{
        {'#', &std::isdigit},
        {'_', &std::isspace},
        {'@', &std::isalpha},
        {'?', [](int){ return 1; } }
    };

    return std::equal(input.begin(), input.end(), pattern.begin(), [](char ch, char mask) -> bool {
        if(auto found{validators.find(mask)}; found != validators.end())
        {
            // The pattern's current element was found in the validators. Call the
            // corresponding function.
            return (*found->second)(ch);
        }
        else
        {
            // The pattern's current element was not found in the validators. The
            // characters have to be an exact match.
            return (ch == mask);
        }
    });
}

int main()
{/*
    //Stream states:

    //Input validation:

    //String validation:

    std::string name{};

    do
    {
        std::cout << "Enter your name: ";
        std::getline(std::cin, name); // get the entire line, including spaces

    }   while(!isValidName(name));

    std::cout << "Hello " << name << "!\n";

    //Now let’s take a look at another example where we are going to ask the user to enter their phone number:
    std::string phoneNumber{};

    do
    {
        std::cout << "Enter a phone number (###) ###-####: ";
        std::getline(std::cin, phoneNumber);

    }   while(!inputMatches(phoneNumber, "(###) ###-####"));

    std::cout << "You entered: " << phoneNumber << '\n';

*/
    //Numeric validation:

    int age{};

    while(true)
    {
        std::cout << "Enter your age: ";
        std::cin >> age;

        if(std::cin.fail())// no extraction took place
        {
            std::cin.clear();// reset the state bits back to goodbit so we can use ignore()

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// clear out the bad input from the stream
            continue;// try again
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// clear out any additional input from the stream

        if(std::cin.gcount() > 1)// if we cleared out more than one additional character
        {
            continue; // we'll consider this input to be invalid
        }

        if(age <= 0)// make sure age is positive
            continue;
        
        break;
    }
    
    std::cout << "You are " << age << " years old\n";


    //Numeric validation as a string:
    //https://www.learncpp.com/cpp-tutorial/stream-states-and-input-validation/


    return 0;
}