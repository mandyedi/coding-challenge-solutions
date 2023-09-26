#include <iostream>
#include <fstream>
#include "json.hpp"

// https://github.com/nlohmann/json

using json = nlohmann::json;

void traverseJSON_PartOne(const json& jsonData, int &sum) {
    if (jsonData.is_object())
    {
        for (json::const_iterator it = jsonData.begin(); it != jsonData.end(); ++it)
        {
            //std::cout << "Key: " << it.key() << std::endl;
            traverseJSON_PartOne(it.value(), sum);
        }
    }
    else if (jsonData.is_array())
    {
        for (const auto& item : jsonData)
        {
            traverseJSON_PartOne(item, sum);
        }
    }
    else
    {
        //std::cout << "Value: " << jsonData << std::endl;
        if (jsonData.is_number_integer())
        {
            sum += jsonData.get<int>();
        }
    }
}

void traverseJSON_PartTwo(const json& jsonData, int& sum) {
    if (jsonData.is_object())
    {
        for (auto& el : jsonData.items())
        {
            if (el.value().is_string() && el.value().get<std::string>() == "red")
            {
                return;
            }
        }

        for (json::const_iterator it = jsonData.begin(); it != jsonData.end(); ++it)
        {
            //std::cout << "Key: " << it.key() << std::endl;
            traverseJSON_PartTwo(it.value(), sum);
        }
    }
    else if (jsonData.is_array())
    {
        for (const auto& item : jsonData)
        {
            traverseJSON_PartTwo(item, sum);
        }
    }
    else
    {
        //std::cout << "Value: " << jsonData << std::endl;
        if (jsonData.is_number_integer())
        {
            sum += jsonData.get<int>();
        }
    }
}

int main()
{
    std::ifstream f("012_input.json");
    json data = json::parse(f);

    int sum = 0;
    traverseJSON_PartTwo(data, sum);

    std::cout << "sum: " << sum << "\n";

    std::cin.get();
    return 0;
}
