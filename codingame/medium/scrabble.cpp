/*
Title: Scrable
Tags: medium, loops, conditions
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<char, int> scoreTable =
    {
        {'e', 1},
        {'a', 1},
        {'i', 1},
        {'o', 1},
        {'n', 1},
        {'r', 1},
        {'t', 1},
        {'l', 1},
        {'s', 1},
        {'u', 1},
        {'d', 2},
        {'g', 2},
        {'b', 3},
        {'c', 3},
        {'m', 3},
        {'p', 3},
        {'f', 4},
        {'h', 4},
        {'v', 4},
        {'w', 4},
        {'y', 4},
        {'k', 5},
        {'j', 6},
        {'x', 6},
        {'q', 4},
        {'z', 4}
    };

int GetScore(const string &word) {
    int score = 0;
    for( char letter : word) {
        score += scoreTable[letter];
    }
    return score;
}

int main()
{


    int n;
    cin >> n; cin.ignore();

    vector<pair<string, int>> wordsWithScore;

    for (int i = 0; i < n; i++) {
        string w;
        getline(cin, w);
        wordsWithScore.push_back(make_pair(w, 0));
    }

    string lettersOriginal;
    getline(cin, lettersOriginal);

    for (auto &item : wordsWithScore) {
        string letters = lettersOriginal;
        const string &word = item.first;
        // cerr << "word: " << word << endl;
        // cerr << "letters:\n";
        for (char letter : word) {
            // cerr << letter << " ";
            size_t pos = letters.find(letter);
            if (pos != string::npos) {
                // cerr << "found ";
                item.second += scoreTable[letter];
                letters.erase(pos, 1);
                // cerr << "score: " << item.second << " ";
            }
            else {
                item.second = 0;
                break;
            }
        }
        // cerr << endl;
    }

    // for (auto item : wordsWithScore) {
    //     cerr << item.first << " " << item.second << endl;
    // }

    auto best = wordsWithScore.begin();
    for (auto item = wordsWithScore.begin(); item != wordsWithScore.end(); ++item) {
        if (item->second > best->second) {
            best = item;
        }
    }

    cout << best->first;
}
