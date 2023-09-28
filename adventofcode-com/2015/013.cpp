#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

void GetTokens(const std::string& line, std::vector<std::string> &tokens)
{
    tokens.clear();
    std::stringstream lineStream(line);
    std::string token;
    while (std::getline(lineStream, token, ' '))
    {
        tokens.push_back(token);
    }
}

std::string GetKey(const std::string& str0, const std::string& str1)
{
    std::string key = str0 + str1;
    std::sort(key.begin(), key.end());
    return key;
}

int main()
{
    int numberOfGuests = 9;      // 8: part one, 9: part two

    //std::ifstream infile("013_input.txt");
    std::ifstream infile("013_part_two_input.txt");

    std::vector<std::string> guests;
    guests.reserve(numberOfGuests);

    std::unordered_map<std::string, int> costs;
    std::unordered_map<std::string, std::string> guestsFromKey;

    std::string line;
    while (std::getline(infile, line))
    {
        // Tokenize line by space
        std::vector<std::string> tokens;
        GetTokens(line, tokens);

        // Extarct names and cost between them
        std::string guest0 = std::move(tokens[0]);
        std::string guest1 = std::move(tokens[10].substr(0, tokens[10].length() - 1));
        int cost = (tokens[2] == "gain" ? 1 : -1) * std::atoi(tokens[3].c_str());

        // Build up the cost between guests
        std::string key = GetKey(guest0, guest1);
        if (costs.find(key) == costs.end())
        {
            costs[key] = 0;
        }
        costs[key] += cost;

        // Store guests by hash
        if (guestsFromKey.find(key) == guestsFromKey.end())
        {
            guestsFromKey[key] = guest0 + " " + guest1;
        }

        // Build up guest list
        if (std::find(guests.begin(), guests.end(), guest0) == guests.end())
        {
            guests.push_back(guest0);
        }
    }

    // Find highest cost
    int maxCost = 0;
    do
    {
        int cost = 0;
        for (unsigned int i = 0; i < numberOfGuests; i++)
        {
            int next = 0;
            if (i == numberOfGuests - 1)
            {
                next = 0;
            }
            else
            {
                next = i+1;
            }
            const std::string guest0 = guests[i];
            const std::string guest1 = guests[next];
            std::string key = GetKey(guest0, guest1);
            cost += costs[key];
        }

        if (cost > maxCost)
        {
            maxCost = cost;
        }
    }
    while (std::next_permutation(guests.begin(), guests.end()));

    std::cout << "max cost: " << maxCost;

    // Debug
    //for (auto& it : costs)
    //{
    //    std::cout << guestsFromKey[it.first] << " " << it.second << "\n";
    //}

    std::cin.get();
    return 0;
}
