/*
Title: Mayan Calculation
Tags: strings, radix
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

char digitToChar(long int digit) {
    if (digit >= 0 && digit <= 9) {
        return (char)(digit + '0');
    }
    else {
        return (char)(digit - 10 + 'A');
    }
}

int charToDigit(char c)
{
    if (c >= '0' && c <= '9') {
        return (int)c - '0';
    }
    else {
        return (int)c - 'A' + 10;
    }
}

long int toDec(const string &number) {
    long int s = static_cast<long int>(number.size());
    if (s == 0) {
        return 0;
    }
    long int dec = 0;
    for (long int i = s - 1, j = 0; i >= 0; i--, j++) {
        long int x = charToDigit(number[i]);
        long int y = static_cast<long int>(pow(20, j));
        dec += x * y;
    }
    return dec;
}

string toBase20(long int number)
{
    if (number == 0) {
        return "0";
    }

    string result;
    long int index = 0;

    while (number > 0)
    {
        result  += digitToChar(number % 20);
        number /= 20;
    }

    return result;
}

long int eval(long int a, long int b, char op) {
    long int result = 0;
    switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
    };
    return result;
}

int main()
{
    vector<string> numbers(20, "");
    unordered_map<string, long int> numbersMap;

    int l;
    int h;
    cin >> l >> h; cin.ignore();
    cerr << l << " " << h << endl;
    for (int i = 0; i < h; i++) {
        string numeral;
        cin >> numeral; cin.ignore();
        for (int j = 0; j < 20; j++) {
            numbers[j] += numeral.substr(j*l, l);
        }
    }

    // for (size_t i = 0; i < numbers.size(); i++) {
    //     cerr << i << ": " << numbers[i] << endl;
    // }

    for (long int i = 0; i < 20; i++) {
        numbersMap[numbers[i]] = i;
    }

    // for (auto &item : numbersMap) {
    //     cerr << item.first << " " << item.second << endl;
    // }

    int s1;
    cin >> s1; cin.ignore();
    int j = 1;
    string numberString;
    string base20StringA;
    for (int i = 0; i < s1; i++) {
        string num_1line;
        cin >> num_1line; cin.ignore();
        numberString += num_1line;
        if (j == h) {
            long int digit = numbersMap[numberString];
            base20StringA += digitToChar(digit);
            numberString = "";
            j = 1;
        }
        else {
            j++;
        }
    }
    cerr << "base20StringA: " << base20StringA << endl;

    int s2;
    cin >> s2; cin.ignore();
    j = 1;
    numberString = "";
    string base20StringB = "";
    for (int i = 0; i < s2; i++) {
        string num_2line;
        cin >> num_2line; cin.ignore();
        numberString += num_2line;
        if (j == h) {
            long int digit = numbersMap[numberString];
            base20StringB += digitToChar(digit);
            numberString = "";
            j = 1;
        }
        else {
            j++;
        }
    }
    cerr << "base20StringB: " << base20StringB << endl;

    char operation;
    cin >> operation; cin.ignore();

    long int a = toDec(base20StringA);
    long int b = toDec(base20StringB);
    long int resultBase10 = eval(a, b, operation);
    cerr << "a: " << a << " b: " << b << endl;
    cerr << "result base 10: " << resultBase10 << endl;

    string resultBase20 = toBase20(resultBase10);
    cerr << "result base 20: " << resultBase20 << endl;

    int size = resultBase20.size();
    for (int i = size - 1; i >= 0; i--) {
        char digitBase20 = resultBase20[i];
        int index = charToDigit(digitBase20);
        string digit = numbers[index];

        size_t sizeMayanNumber = digit.size();
        for (int j = 0; j < sizeMayanNumber; j += l) {
            cout << digit.substr(j, l) << endl;
        }
    }
}
