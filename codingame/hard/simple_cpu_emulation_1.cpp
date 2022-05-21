/*
Title: Simple CPU Emulation 1
Tags: stack, interpreters
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>

using namespace std;

enum class OPCODE
    {
        EXIT = '0',
        LOAD = '1',
        ADD = '2',
        SUB = '3',
        OR = '4',
        AND = '5',
        XOR = '6',
        SKIP_EQ = '7',
        SKIP_NEQ = '8',
        SKIP_REQ = '9',
        SKIP_RNEQ = 'A'
    };

int registers[3] = {};

int GetLastTwoValues(const char *c1, const char *c2) {
    string s = string(1, *c1) + *c2;
    return stoi(s, nullptr, 16);
}

void SetRegister(char *reg, const char *c1, const char *c2) {
    registers[*reg - '0'] = GetLastTwoValues(c1, c2);
}

int GetInt(const char *c) {
    return *c - '0';
}

int main()
{
    string program;
    getline(cin, program);

    bool execute = true;
    char *opcode = program.data();
    while(execute) {

        switch((OPCODE)(*opcode)) {
            case OPCODE::EXIT: {
                cerr << "Exit\n";
                execute = false;
                break;
            }

            case OPCODE::LOAD: {
                cerr << "Load\n";
                SetRegister(opcode + 1, opcode + 2, opcode + 3);
                break;
            }

            case OPCODE::ADD: {
                cerr << "Add\n";
                int x = registers[GetInt(opcode + 2)];
                int y = registers[GetInt(opcode + 3)];
                int sum = x + y;
                if ( sum > 255) {
                    registers[2] = 1;
                    registers[GetInt(opcode + 2)] = sum & 255;
                }
                else {
                    registers[2] = 0;
                    registers[GetInt(opcode + 2)] = sum;
                }
                break;
            }

            case OPCODE::SUB: {
                cerr << "Sub\n";
                int x = registers[GetInt(opcode + 2)];
                int y = registers[GetInt(opcode + 3)];
                int diff = x - y;
                cerr << "diff: " << diff << endl;
                if ( diff < 0) {
                    registers[2] = 1;
                    registers[GetInt(opcode + 2)] = 256 + diff;
                }
                else {
                    registers[2] = 0;
                    registers[GetInt(opcode + 2)] = diff;
                }
                break;
            }

            case OPCODE::OR: {
                cerr << "Or\n";
                int x = registers[GetInt(opcode + 2)];
                int y = registers[GetInt(opcode + 3)];
                registers[GetInt(opcode + 2)] = x | y;
                break;
            }

            case OPCODE::AND: {
                cerr << "And\n";
                int x = registers[GetInt(opcode + 2)];
                int y = registers[GetInt(opcode + 3)];
                registers[GetInt(opcode + 2)] = x & y;
                break;
            }

            case OPCODE::XOR: {
                cerr << "Xor\n";
                int x = registers[GetInt(opcode + 2)];
                int y = registers[GetInt(opcode + 3)];
                registers[GetInt(opcode + 2)] = x ^ y;
                break;
            }

            case OPCODE::SKIP_EQ: {
                cerr << "Skip if R == value\n";
                int k = registers[GetInt(opcode + 1)];
                int value = GetLastTwoValues(opcode + 2, opcode + 3);
                if (k == value) {
                    opcode += 4;
                }
                break;
            }

            case OPCODE::SKIP_NEQ: {
                cerr << "Skip if R != value\n";
                int k = registers[GetInt(opcode + 1)];
                int value = GetLastTwoValues(opcode + 2, opcode + 3);
                if (k != value) {
                    opcode += 4;
                }
                break;
            }

            case OPCODE::SKIP_REQ: {
                cerr << "Skip if R == R\n";
                int x = registers[GetInt(opcode + 2)];
                int y = registers[GetInt(opcode + 3)];
                if (x == y) {
                    opcode += 4;
                }
                break;
            }

            case OPCODE::SKIP_RNEQ: {
                cerr << "Skip if R != R\n";
                int x = registers[GetInt(opcode + 2)];
                int y = registers[GetInt(opcode + 3)];
                if (x != y) {
                    opcode += 4;
                }
                break;
            }

            default: {
                cerr << "Error: unkown opcode\n";
                execute = false;
                break;
            }
        };

        if (execute) {
            // Check if we are on 0000 after one of the skips
            if (*opcode == 10) {
                execute = false;
            }
            else {
                opcode += 4;
            }

            cerr << "registers: " << registers[0] << " " << registers[1] << " " << registers[2] << endl;
            cerr << "------------------\n";
        }
    }

    cout << (int)registers[0] << " " << (int)registers[1] << " " << (int)registers[2] << endl;
}
