/**
 * Project Euler Problem 13
 */

#include <iostream>
#include <fstream>
#include <vector>

#include "ttmath.h"

using namespace std;
#define uint unsigned int

int main()
{
    // init
    uint **numbers;
    numbers = new uint*[100];
    for(uint row=0; row<100; row++)
    {
        numbers[row] = new uint[50];
    }

    // read file
    std::ifstream in("C:\\dev\\qt\\cpp\\numbers.txt");
    std::vector<char> contents((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());

    // convert to char array
    char **cNumbers;
    cNumbers = new char*[100];
    for(uint row=0; row<100; row++)
    {
        cNumbers[row] = new char[50];
    }
    uint row = 0;
    uint col = 0;
    for(vector<char>::iterator it = contents.begin(); it != contents.end(); ++it)
    {
        if(*it == '\n')
        {
            row++;
            col = 0;
        }
        else
        {
            cNumbers[row][col] = *it;
            col++;
        }
    }

    // add numbers
    typedef ttmath::UInt<TTMATH_BITS(500)> Int;

    Int a, sum = 0;
    for(uint row=0; row<100; row++)
    {
        sum += (Int)cNumbers[row];
    }

    cout << sum;

    cout << "\n\n";
    return 0;
}

