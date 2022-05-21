/*
Title: MCxxxx Microcontroller Simulation
Tags: interpreters
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <queue>

using namespace std;

unordered_map<string, int> registers =
{
    {"acc", 0},
    {"dat", 0},
    {"x0", 0},
    {"x1", 0}
};

queue<int> input;
string output = "";

void GetTokens( const std::string &line, std::vector<string> &tokens )
{
    tokens.clear();
    std::stringstream lineStream( line );
    std::string token;
    while ( std::getline( lineStream, token, ' ' ) )
    {
        tokens.push_back( static_cast<string>(token) );
    }
}

bool IsRegister(const string &s) {
    return s == "x0" || s == "x1";
}

void SetRegisterData(const string &name, int data) {
    if (name == "x1") {
        output += to_string(data) + " ";
    }
    else {
        if (data < -999) {
            data = -999;
        }
        if (data > 999) {
            data = 999;
        }
        registers[name] = data;
    }
}

int GetRegisterData(const string &name) {
    if (name == "x0") {
        int x0 = input.front();
        input.pop();
        registers["x0"] = x0;
    }
    return registers[name];
}

int GetLiteral(const string &s) {
    if (registers.find(s) != registers.end() ) {
        return GetRegisterData(s);
    }
    else {
        return stoi(s);
    }
}

int main()
{
    unordered_map<string, int> labels;

    int k;
    cin >> k; cin.ignore();
    for (int i = 0; i < k; i++) {
        int input_data;
        cin >> input_data; cin.ignore();
        input.push(input_data);
    }

    vector<string> code;
    int n;
    cin >> n; cin.ignore();
    int line_count = 0;
    for (int i = 0; i < n; i++) {
        string line_of_code;
        getline(cin, line_of_code);

        if(line_of_code.back() == ' ') {
            line_of_code = line_of_code.substr(0, line_of_code.length() - 1);
        }

        size_t pos = line_of_code.find(":");
        if (pos != string::npos) {
            if (line_of_code.back() == ':') {
                labels[line_of_code.substr(0, pos)] = line_count;
                code.push_back(line_of_code);
            }
            else
            {
                labels[line_of_code.substr(0, pos)] = line_count;
                code.push_back(line_of_code.substr(0, pos + 1));
                code.push_back(line_of_code.substr(pos + 2));
                line_count++;
            }

        }
        else {
            code.push_back(line_of_code);
        }
        line_count++;
    }

    cerr << "----PROCESSED CODE:----\n";
    for (auto &line : code) {
        cerr << line << endl;
    }
    cerr << "-----------------------\n";

    // -1: all disabled
    //  0: last condition was false, + disabled, - enabled
    //  1: last condition was true,  + enabled,  - disabled
    int condition_state = -1;

    int index = 0;
    bool execute = true;
    while (execute) {
        string &line = code[index];
        vector<string> tokens;
        GetTokens(line, tokens);

        cerr << "execute line: " << line << endl;

        bool one_time_execution = false;
        if (tokens[0] == "@") {
            cerr << "@\n";
            line = line.substr(2);
            tokens.erase(tokens.begin());
            one_time_execution = true;
        }

        // This only temporary changes the line
        // If we jump back, the condition can be tested again
        if (tokens[0] == "+") {
            cerr << "+\n";
            if (condition_state == 1) {
                tokens.erase(tokens.begin());
                condition_state = -1;
            }
            else {
                tokens[0] = "#";
            }
        }

        if (tokens[0] == "-") {
            cerr << "-\n";
            if (condition_state == 0) {
                tokens.erase(tokens.begin());
                condition_state = -1;
            }
            else {
                tokens[0] = "#";
            }
        }

        if (tokens[0] == "#") {
            cerr << "#\n";
            index++;
        }
        else if (tokens[0].back() == ':') {
            cerr << ":\n";
            index++;
        }
        else if (tokens[0] == "mov") {
            cerr << "mov\n";
            SetRegisterData(tokens[2], GetLiteral(tokens[1]));
            index++;
        }
        else if (tokens[0] == "jmp") {
            index = labels[tokens[1]] + 1;
        }
        else if (tokens[0] == "add") {
            int acc = GetRegisterData("acc");
            int data = GetLiteral(tokens[1]);
            SetRegisterData("acc", acc + data);
            index++;
        }
        else if (tokens[0] == "sub") {
            cerr << "sub\n";
            int acc = GetRegisterData("acc");
            int data = GetLiteral(tokens[1]);
            SetRegisterData("acc", acc - data);
            index++;
        }
        else if (tokens[0] == "mul") {
            int acc = GetRegisterData("acc");
            int data = GetLiteral(tokens[1]);
            SetRegisterData("acc", acc * data);
            index++;
        }
        else if (tokens[0] == "not") {
            int acc = GetRegisterData("acc");
            if (acc == 0) {
                SetRegisterData("acc", 100);
            }
            else {
                SetRegisterData("acc", 0);
            }
            index++;
        }
        else if (tokens[0] == "dgt") {
            cerr << "dgt\n";
            string acc = to_string(GetRegisterData("acc"));
            int i = acc.length() - 1 - GetLiteral(tokens[1]);
            if (i < 0) {
                SetRegisterData("acc", 0);
            }
            else {
                SetRegisterData("acc", acc[i] - '0');
            }
            index++;
        }
        else if (tokens[0] == "dst") {
            cerr << "dst\n";
            string acc = to_string(GetRegisterData("acc"));

            string new_acc = "";
            for (int i = 0; i < 3 - acc.length(); i++) {
                new_acc += "0";
            }
            new_acc += acc;

            int i = 2 - GetLiteral(tokens[1]);
            int value = GetLiteral(tokens[2]);
            if (i < 0) {
                SetRegisterData("acc", 0);
            }
            else {
                new_acc.replace(i, 1, to_string(value));
                SetRegisterData("acc", stoi(new_acc));
            }
            index++;
        }
        else if (tokens[0] == "teq") {
            cerr << "teq\n";
            int value1 = GetLiteral(tokens[1]);
            int value2 = GetLiteral(tokens[2]);
            condition_state = value1 == value2 ? 1 : 0;
            index++;
        }
        else if (tokens[0] == "tgt") {
            cerr << "tgt\n";
            int value1 = GetLiteral(tokens[1]);
            int value2 = GetLiteral(tokens[2]);
            condition_state = value1 > value2 ? 1 : 0;
            index++;
        }
        else if (tokens[0] == "tlt") {
            cerr << "tlt\n";
            int value1 = GetLiteral(tokens[1]);
            int value2 = GetLiteral(tokens[2]);
            condition_state = value1 < value2 ? 1 : 0;
            index++;
        }
        else if (tokens[0] == "tcp") {
            cerr << "tcp\n";
            int value1 = GetLiteral(tokens[1]);
            int value2 = GetLiteral(tokens[2]);
            if (value1 > value2) {
                condition_state = 1;
            }
            else if (value1 < value2) {
                condition_state = 0;
            }
            index++;
        }
        else {
            cerr << "Error: undefined command: " << tokens[0] << "\n";
            execute = false;
        }

        if (one_time_execution) {
            line = "# " + line;
            tokens.insert(tokens.begin(), "#");
        }

        if (index >= code.size()) {
            execute = false;
        }

        cerr << "-----------------------\n";
    }

    output.back() = '\n';
    cout << output;
}
