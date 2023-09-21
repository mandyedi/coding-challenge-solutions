#include <iostream>

void print(int* ints)
{
    for (unsigned int i = 0; i < 8; i++)
    {
        std::cout << static_cast<char>(ints[i]);
    }
    std::cout << std::endl;
}

bool isIncreasingStraight(int* ints)
{
    for (unsigned int i = 0; i < 6; i++)
    {
        if (ints[i] == ints[i + 1] - 1 && ints[i] == ints[i + 2] - 2)
        {
            return true;
        }
    }
    return false;
}

bool hasIllegalLetters(int* ints)
{
    // 105: i
    // 111: o
    // 108: l
    for (unsigned int i = 0; i < 8; i++)
    {
        if (ints[i] == 105 || ints[i] == 111 || ints[i] == 108)
        {
            return true;
        }
    }
    return false;
}

bool hasTwoPairs(int* ints)
{
    int numberOfPairs = 0;
    for (unsigned int i = 0; i < 7; i++)
    {
        if (ints[i] == ints[i + 1])
        {
            numberOfPairs++;
            i++;
        }
    }

    return numberOfPairs == 2;
}

bool isValid(int* ints)
{
    if (isIncreasingStraight(ints) && !hasIllegalLetters(ints) && hasTwoPairs(ints))
    {
        return true;
    }
    return false;
}

int main()
{
    //std::string pswd( "hxbxwxba" );   // first input
    std::string pswd( "hxbyxyzz" );     // second input
    size_t s = pswd.size();

    int ints[8];
    for (unsigned int i = 0; i < 8; i++)
    {
        ints[i] = static_cast<int>(pswd[i]);
    }

    // 97: a
    // 122: z
    while (isValid(ints) == false)
    {
        for (int i = 7; i >= 0; i--)
        {
            //print(ints);
            ints[i]++;

            if (ints[i] == 123)
            {
                ints[i] = 97;
            }
            else
            {
                break;
            }
        }
    }

    print(ints);

    std::cin.get();
    return 0;
}
