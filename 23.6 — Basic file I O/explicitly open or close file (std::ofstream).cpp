#include <iostream>
#include <fstream>

int main()
{
    std::ofstream oko{ "Another sample.txt" };
    oko << "and what happen now ?" << '\n';
    oko << "and  now ?" << '\n';
    oko.close();// explicitly close the file



    oko.open("Another sample.txt", std::ios::app);// Oops, we forgot something
    oko << "This is another line in this file" << '\n';
    oko.close();

    


    return 0;
}