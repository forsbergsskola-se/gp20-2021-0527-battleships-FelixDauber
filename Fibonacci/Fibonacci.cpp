// Fibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//Could be simplified by storing an array of numbers you've already discovered... As performance dies after a point
int getValue(int input)
{
    if (input < 2) {
        return input;
    }
    return getValue(input - 1) + getValue(input - 2);
}

bool getInput() {
    char input;
    std::cout << "Keep going? Y/N";
    while (true)
    {
        std::cin >> input;

        putchar(tolower(input));

        if (input == 'y') return true;

        if (input == 'n') return false;
    }
}

int main()
{
    int i = 0;
    while (getInput())
    {
        std::cout << getValue(i);
        i++;
    }
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
