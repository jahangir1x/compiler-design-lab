#include <bits/stdc++.h>
using namespace std;

string convertToGenericExpression(string input) {
    string genericExpression = "";
    for (int i = 0; i < input.size(); i++) {
        if (isdigit(input[i]) && i == 0) {
            genericExpression += 'x';
        } else if (isdigit(input[i]) && i > 0 && !isdigit(input[i - 1])) {
            genericExpression += 'x';
        } else if (!isdigit(input[i])) {
            genericExpression += input[i];
        }
    }
    return genericExpression;
}

int main() {
    map<string, string> rules = {
        {"S+S", "S"},
        {"S*S", "S"},
        {"S-S", "S"},
        {"(S)", "S"}};

    string input;
    cin >> input;
    // input = "8434+(5343+2934)*+234348";
    input = convertToGenericExpression(input);
    string parsedString = "";
    for (int idx = 0; idx < input.size(); idx++) {
        parsedString += (input[idx] == 'x') ? 'S' : input[idx];
        for (int stackIdx = parsedString.size() - 1; stackIdx >= 0; stackIdx--) {
            string stackSubstring = parsedString.substr(stackIdx, INT_MAX);
            if (rules.count(stackSubstring) > 0) {
                parsedString = parsedString.substr(0, stackIdx) + rules[stackSubstring];
            }
        }
    }
    if (parsedString == "S") {
        cout << "Accepted" << endl;
    } else {
        cout << "Rejected" << endl;
    }
}