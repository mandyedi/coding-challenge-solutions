/*
Title: Hidden Messages in Images
Tags: easy, image processing, loops
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int w;
    int h;
    cin >> w >> h; cin.ignore();
    string binary_string;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int pixel;
            cin >> pixel; cin.ignore();
            binary_string += to_string((pixel & 1));
            if ((i * w + j + 1) % 8 == 0) {
                int x = std::stoi(binary_string, nullptr, 2);
                cout << (char)x;
                binary_string = "";
            }
        }
    }
}
