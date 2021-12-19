/*
Title: Hangman
Tags: hard, strings, string manipulation, 2D array
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    string word;
    getline(cin, word);
    string chars;
    getline(cin, chars);

    vector<string> errors;
    errors.push_back("+--+\n|\n|\n|\\\n");
    errors.push_back("+--+\n|  o\n|\n|\\\n");
    errors.push_back("+--+\n|  o\n|  |\n|\\\n");
    errors.push_back("+--+\n|  o\n| /|\n|\\\n");
    errors.push_back("+--+\n|  o\n| /|\\\n|\n");
    errors.push_back("+--+\n|  o\n| /|\\\n|\\/\n");
    errors.push_back("+--+\n|  o\n| /|\\\n|\\/ \\\n");

    chars.erase(remove(chars.begin(), chars.end(), ' '), chars.end());

    int errorCount = 0;
    string word2 = "";
    for (auto letter : word) {
        if (letter != ' ') {
            if (chars.find(tolower(letter)) == string::npos) {
                word2 += '_';
            }
            else {
                word2 += letter;
            }
        }
        else {
            word2 += ' ';
        }
    }

    std::transform(word.begin(), word.end(), word.begin(),
    [](unsigned char c){ return std::tolower(c); });

    string checked;
    for (auto letter : chars) {
        if (checked.find(letter) != string::npos) {
            errorCount++;
        }
        else if (word.find(letter) == string::npos) {
            errorCount++;
            checked += letter;
        }
        else {
            checked += letter;
        }
    }

    cout << errors[errorCount];
    cout << word2 << endl;
}
