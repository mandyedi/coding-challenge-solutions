/*
Title: Equivalent Resistance, Circuit Building
Tags: parsing, physics, stack
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <sstream>
#include <iomanip>

using namespace std;

void buildTokens(const string &circuit, vector<string> &tokens, const unordered_map<string, float> &valuesMap)
{
    stringstream lineStream(circuit);
    string token;
    while (std::getline(lineStream, token, ' '))
    {
        if (token != "(" && token != "[" && token != ")" && token != "]") {
            token = to_string(valuesMap.at(token));
        }
        tokens.push_back(token);
    }
}

void solve(stack<float> &values, const string &brace) {
    if (brace == "(") {
        float result = values.top();
        values.pop();
        while (!values.empty()) {
            result += values.top();
            values.pop();
        }
        values.push(result);
    }
    else {
        float result = values.top();
        values.pop();
        bool moreThanOne = false;
        if (!values.empty()) {
            moreThanOne = true;
            result = 1.0f / result;
        }
        while (!values.empty()) {
            result += 1.0f / values.top();
            values.pop();
        }
        if (moreThanOne) {
            result = 1.0f / result;
        }
        values.push(result);
    }
}

int main()
{
unordered_map<string, float> valuesMap;
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string name;
        float r;
        cin >> name >> r; cin.ignore();
        valuesMap.insert({ name, r });
    }
    string circuit;
    getline(cin, circuit);

    stack<string> s;
    vector<string> tokens;
    buildTokens(circuit, tokens, valuesMap);

    for (auto &token : tokens) {
        if (token == ")" || token == "]") {
            stack<float> tempValues;

            while (!s.empty() && s.top() != "(" && s.top() != "[") {
                tempValues.push(stof(s.top()));
                s.pop();
            }

            solve(tempValues, s.top());
            s.pop();

            s.push(to_string(tempValues.top()));
        }
        else {
            s.push(token);
        }
    }

    cout << fixed << setprecision(1) << stof(s.top()) << endl;
}
