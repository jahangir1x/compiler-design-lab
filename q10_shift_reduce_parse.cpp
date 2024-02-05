#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, string> rules = {
        {"S+S", "S"},
        {"S*S", "S"},
        {"S-S", "S"},
        {"(S)", "S"}
    };

    string input;
    cin >> input;
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