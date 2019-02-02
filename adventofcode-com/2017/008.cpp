#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> registers;
int highest = 0;

void incRegister( string reg, int i )
{
    map<string, int>::iterator it;
    it = registers.find( reg );
    if ( it == registers.end() )
    {
        registers[reg] = 0;
    }
    registers[reg] += i;
    if ( registers[reg] > highest )
    {
        highest = registers[reg];
    }
}

void decRegister( string reg, int i )
{
    map<string, int>::iterator it;
    it = registers.find( reg );
    if ( it == registers.end() )
    {
        registers[reg] = 0;
    }
    registers[reg] -= i;
}

int getRegister( string reg )
{
    map<string, int>::iterator it;
    it = registers.find( reg );
    if ( it == registers.end() )
    {
        registers[reg] = 0;
    }
    return registers[reg];
}

bool evaluateCondition( string reg, string condition, int value )
{
    int regValue = getRegister( reg );
    // cout << reg << ":" << regValue << " " << condition << " " << value << "\n";
    bool result = false;
    if ( condition.compare( ">" ) == 0 )
    {
        result = regValue > value;
    }
    else if ( condition.compare( "<" ) == 0 )
    {
        result = regValue < value;
    }
    else if ( condition.compare( ">=" ) == 0 )
    {
        result = regValue >= value;
    }
    else if ( condition.compare( "<=" ) == 0 )
    {
        result = regValue <= value;
    }
    else if ( condition.compare( "==" ) == 0 )
    {
        result = regValue == value;
    }
    else if ( condition.compare( "!=" ) == 0 )
    {
        result = regValue != value;
    }
    else
    {
        cout << "WHAT\n";
    }

    // cout << "  " << result << "\n";
    return result;
}

int main(int argc, char **argv)
{
    ifstream infile( "008.txt" );
    string line;

    int numbers[16][16];
    int i = 0;
   
    while (std::getline(infile, line))
    {
        string buf;
        stringstream ss( line );
        vector<string> tokens;

        while (ss >> buf)
        {
            tokens.push_back( buf );
        }

        string reg = tokens[0];
        string op = tokens[1];
        int    value = stoi( tokens[2] );
        string regCondition = tokens[4];
        string condition = tokens[5];
        int    valueCondition = stoi( tokens[6] );

        if ( evaluateCondition( regCondition, condition, valueCondition ) )
        {
            if ( op.compare( "inc" ) == 0 )
            {
                incRegister( reg, value );
            }
            else
            {
                decRegister( reg, value );
            }
        }

    }

    map<string, int>::iterator itMax = max_element( registers.begin(), registers.end(),
        [](const pair<string, int> &a, const pair<string, int> &b ) {
            return a.second < b.second;
        });

    cout << itMax->second << "\n";
    cout << highest;

    return 0;
}