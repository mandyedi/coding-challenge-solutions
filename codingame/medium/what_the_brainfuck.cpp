/*
Title: What the Brainfuck!
Tags: medium, pathfinding, bfs, graphs
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory>

using namespace std;

int main()
{
    int l;
    int s;
    int n;
    cin >> l >> s >> n; cin.ignore();

    shared_ptr<int[]> memory(new int[s]);
    for (int i = 0; i < s; i++) {
        memory[i] = 0;
    }

    string program;
    for (int i = 0; i < l; i++) {
        string r;
        getline(cin, r);

        const string instructions = "><+-.,[]";
        r.erase(
            remove_if(r.begin(), r.end(),
                [&instructions](const char &c) {
                    return instructions.find(c) == string::npos;
                }
            ), r.end()
        );

        program += r;
    }

    queue<int> inputs;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c; cin.ignore();
        inputs.push(c);
    }

    int bracket = 0;
    for(char c : program) {
        if (c == '[') {
            bracket--;
        }
        else if (c == ']') {
            bracket++;
        }
    }

    if (bracket != 0) {
        cout << "SYNTAX ERROR";
        return 0;
    }

    int pointer = 0;
    int program_index = 0;
    int program_size = program.length();
    while(program_index < program_size) {

        char instruction = program[program_index];

        switch(instruction) {
            case '>': {
                pointer++;
                if (pointer > s - 1) {
                    cout << "POINTER OUT OF BOUNDS";
                    return 0;
                }
                program_index++;
                break;
            }
            case '<': {
                pointer--;
                if (pointer < 0) {
                    cout << "POINTER OUT OF BOUNDS";
                    return 0;
                }
                program_index++;
                break;
            }
            case '+': {
                memory[pointer]++;
                program_index++;
                break;
            }
            case '-': {
                memory[pointer]--;
                program_index++;
                break;
            }
            case '.': {
                cout << (char)memory[pointer];
                program_index++;
                break;
            }
            case ',': {
                int value = inputs.front();
                inputs.pop();
                memory[pointer] = value;
                program_index++;
                break;
            }
            case '[': {
                if (memory[pointer] == 0) {
                    int bracket = -1;
                    while(bracket != 0) {
                        instruction = program[++program_index];
                        if (instruction == '[') {
                            bracket--;
                        }
                        else if (instruction == ']') {
                            bracket++;
                        }
                    }
                }
                program_index++;
                break;
            }
            case ']': {
                if (memory[pointer] != 0) {
                    int bracket = 1;
                    while(bracket != 0) {
                        instruction = program[--program_index];
                        if (instruction == '[') {
                            bracket--;
                        }
                        else if (instruction == ']') {
                            bracket++;
                        }
                    }
                }
                program_index++;
                break;
            }
            default : {
                cerr << "Unkown instruction: " << instruction << endl;
                cerr << "program index: " << program_index << endl;
                return 0;
            }
        }

        if (memory[pointer] < 0 || memory[pointer] > 255) {
            cout << "INCORRECT VALUE";
            return 0;
        }
    }
}
