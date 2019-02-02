#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main(int argc, char **argv)
{
    std::ifstream infile("002.txt");
    std::string line;
    int area = 0;
    int ribbon = 0;
    while (std::getline(infile, line))
    {
        int a, b, c;
        std::sscanf(line.c_str(), "%dx%dx%d", &a, &b, &c);

        // area
        area += 2*a*b + 2*a*c + 2*b*c;

        int smallest = 0;
        smallest = a*b < a*c ? a*b : a*c;
        smallest = smallest < b*c ? smallest : b*c;

        area += smallest;

        // ribbon
        int biggest = 0;
        biggest = a > b ? a : b;
        biggest = biggest > c ? biggest : c;

        ribbon += a+a+b+b+c+c - (biggest+biggest);
        ribbon += a*b*c;
    }

    cout << "area:   " << area << endl;
    cout << "ribbon: " << ribbon << endl;

    return 0;
}