#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

typedef unsigned short int uint16;

/*
    123 -> x
    456 -> y
    x AND y -> d
    x OR y -> e
    x LSHIFT 2 -> f
    y RSHIFT 2 -> g
    NOT x -> h
    NOT y -> i
*/

vector< vector<string> > lines;
vector< vector<string> > it;

uint16 EvalCircuit( string variable )
{
    // search variable
    for ( lines)

    // tokenize line

    // call EvalCircuit with new variables and execute operation

}

int main(int argc, char **argv)
{
    ifstream infile("007_test.txt");
    string line;
    
    while (std::getline(infile, line))
    {
        string buf;
        stringstream ss( line );
        vector<string> tokens;

        while (ss >> buf)
        {
            tokens.push_back( buf );
        }

        lines.push_back( tokens );
    }

    return 0;
}

// map<string, uint16> registers;
// vector<string> tokens;

// void SetRegister( string reg, uint16 value )
// {
//     registers[reg] = value;
// }

// uint16 GetLiteral( string s )
// {
//     uint16 value;
//     try
//     {
//         // cout << "test try\n";
//         value = (uint16)stoul( s );
//     }
//     catch (const std::invalid_argument& ia)
//     {
//         // cout << "test catch\n";
//         value = registers[s];
//     }

//     return value;
// }

// bool GetLiteral( string s, uint16 &value )
// {
//     // if ( registers.find( s ) == registers.end() )
//     // {
//     //     value = 0;
//     //     return false;
//     // }

//     try
//     {
//         // cout << "test try\n";
//         value = (uint16)stoul( s );
//     }
//     catch (const std::invalid_argument& ia)
//     {
//         // cout << "test catch\n";
//         // value = registers[s];

//         if ( registers.find( s ) == registers.end() )
//         {
//             value = 0;
//             return false;
//         }
//         else
//         {
//             value = registers[s];
//         }
//     }

//     return true;
// }

// void PrintTokens()
// {
//     cout << "  tokens:   ";
//     for ( int i = 0; i < tokens.size(); i++ )
//     {
//         cout << tokens[i] << " ";
//     }
//     cout << "\n";
// }

// void GetTokens( string &line )
// {
//     tokens.clear();
//     string buf;
//     stringstream ss( line );

//     while (ss >> buf)
//     {
//         tokens.push_back( buf );
//     }

//     // PrintTokens();
// }

// int main(int argc, char **argv)
// {
//     ifstream infile("007.txt");
//     string line;
//     uint16 a, b, c;
//     int cycle = 1;
//     bool debug = false;
//     while (std::getline(infile, line))
//     {
//         // cout << "cycle " << cycle << endl;
//         // cout << "  raw:      " << line << endl;

//         if ( debug )
//             getchar();

//         // a AND b -> c
//         if ( line.find("AND") != string::npos )
//         {
//             GetTokens( line );

//             // cout << "  tokens:   " << tokens[0] << " AND " << tokens[2] << " -> " << tokens[4] << "\n";
//             // cout << "test and\n";
            
//             if ( GetLiteral( tokens[0], a ) && GetLiteral( tokens[2], b ) )
//             {
//                 SetRegister( tokens[4], a & b );
//                 cout << "cycle " << cycle << endl;
//                 cout << "  raw:      " << line << endl;
//                 PrintTokens();
//                 cout << "  executed: " << a << " AND " << b << " -> " << registers[tokens[4]] << "\n";
//             }
//             else
//             {
//                 // cout << "  skip\n";
//             }
//         }
//         // a OR b -> c
//         else if ( line.find("OR") != string::npos )
//         {
//             // cout << "test or\n";
//             GetTokens( line );

//             // cout << "  tokens:   " << tokens[0] << " OR " << tokens[2] << " -> " << tokens[4] << "\n";

//             if ( GetLiteral( tokens[0], a ) && GetLiteral( tokens[2], b ) )
//             {
//                 SetRegister( tokens[4], a | b );
//                 cout << "cycle " << cycle << endl;
//                 cout << "  raw:      " << line << endl;
//                 PrintTokens();
//                 cout << "  executed: " << a << " OR " << b << " -> " << registers[tokens[4]] << "\n";
//             }
//             else
//             {
//                 // cout << "  skip\n";
//             }
//         }
//         // a LSHIFT b -> c
//         else if ( line.find("LSHIFT") != string::npos )
//         {
//             // cout << "test lshift\n";
//             GetTokens( line );

//             // cout << "  tokens:   " << tokens[0] << " LSHIFT " << tokens[2] << " -> " << tokens[4] << "\n";

//             if ( GetLiteral( tokens[0], a ) && GetLiteral( tokens[2], b ) )
//             {
//                 SetRegister( tokens[4], a << b );
//                 cout << "cycle " << cycle << endl;
//                 cout << "  raw:      " << line << endl;
//                 PrintTokens();
//                 cout << "  executed: " << a << " LSHIFT " << b << " -> " << registers[tokens[4]] << "\n";
//             }
//             else
//             {
//                 // cout << "  skip\n";
//             }
//         }
//         // a RSHIFT b -> c
//         else if ( line.find("RSHIFT") != string::npos )
//         {
//             // cout << "test rshift\n";
//             GetTokens( line );

//             // cout << "  tokens:   " << tokens[0] << " RSHIFT " << tokens[2] << " -> " << tokens[4] << "\n";

//             if ( GetLiteral( tokens[0], a ) && GetLiteral( tokens[2], b ) )
//             {
//                 SetRegister( tokens[4], a >> b );
//                 cout << "cycle " << cycle << endl;
//                 cout << "  raw:      " << line << endl;
//                 PrintTokens();
//                 cout << "  executed: " << a << " RSHIFT " << b << " -> " << registers[tokens[4]] << "\n";
//             }
//             else
//             {
//                 // cout << "  skip\n";
//             }
//         }
//         // NOT a -> b
//         else if ( line.find("NOT") != string::npos )
//         {
//             // cout << "test not\n";
//             GetTokens( line );

//             // cout << "  tokens:   " << "NOT " << tokens[1] << " -> " << tokens[3] << "\n";

//             if ( GetLiteral( tokens[1], a ) )
//             {
//                 SetRegister( tokens[3], ~a );
//                 cout << "cycle " << cycle << endl;
//                 cout << "  raw:      " << line << endl;
//                 PrintTokens();
//                 cout << "  executed: " << "NOT " << a << " -> " << registers[tokens[3]] << "\n";
//             }
//             else
//             {
//                 // cout << "  skip\n";
//             }
//         }
//         // a -> b
//         else
//         {
//             GetTokens( line );
//             // cout << "test else\n";

//             // cout << "  tokens:   " << tokens[0] << " -> " << tokens[2] << "\n";

//             // a = GetLiteral( tokens[0] );
//             // b = tokens[2];
//             // SetRegister( b, a );

//             if ( GetLiteral( tokens[0], a ) )
//             {
//                 SetRegister( tokens[2], a );
//                 cout << "cycle " << cycle << endl;
//                 cout << "  raw:      " << line << endl;
//                 PrintTokens();
//                 cout << "  executed: " << a << " -> " << registers[tokens[2]] << "\n";
//                 // debug = true;
//             }
//             else
//             {
//                 // cout << "  skip\n";
//             }
//         }
//         cycle++;
//     }

//     cout << "\n\n";

//     cout << "a " << registers["a"] << endl;

//     // map<string, uint16>::iterator it;
//     // for ( it = registers.begin(); it != registers.end(); ++it )
//     // {
//     //     cout << it->first << " " << it->second << "\n";
//     // }

//     return 0;
// }