#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rules: ";
    cin >> n;
    map<char, vector<string>> grammars;
    char startSymbol = 0;
    while (n--) {
        char variable;
        string rule;
        char temp;
        cin >> variable >> temp >> temp >> rule;
        grammars[variable].push_back(rule);
        if (startSymbol == 0) {
            startSymbol = variable;
        }
    }

    cout << "-------Grammar-------" << endl;
    for (auto grammar : grammars) {
        for (string rule : grammar.second) {
            cout << grammar.first << " -> " << rule << endl;
        }
    }

    // calculate first set with variable and terminals
    map<char, set<char>> firsts;
    for (auto grammar : grammars) {
        for (string rule : grammar.second) {
            char variable = grammar.first;
            char firstChar = rule[0];
            firsts[variable].insert(firstChar);
        }
    }

    // replace variables with terminals
    bool firstsChanged = true;
    while (firstsChanged) {
        firstsChanged = false;
        for (auto first : firsts) {
            char leftVariable = first.first;
            auto rightElements = first.second;
            for (char element : rightElements) {
                if (isupper(element)) {
                    // element is a variable
                    firsts[leftVariable].erase(element);
                    for (char firstOfElement : firsts[element]) {
                        firsts[leftVariable].insert(firstOfElement);
                        if (firstOfElement == '@') {
                            // propagation for @
                            // find respective rule
                            for (string &rule : grammars[leftVariable]) {
                                if 
                            }
                        }
                    }
                    firstsChanged = true;
                }
            }
        }
    }

    // print firsts
    cout << "-------Firsts-------" << endl;
    for (auto first : firsts) {
        cout << first.first << " -> ";
        for (char element : first.second) {
            cout << element << " ";
        }
        cout << endl;
    }

    // calculate follow set with variable and terminals
    map<char, set<char>> follows{{startSymbol, {'$'}}};
    for (auto grammar : grammars) {
        for (string rule : grammar.second) {
            char variable = grammar.first;
            // rule.find()
            for (int ruleIdx = 0; ruleIdx < rule.size(); ruleIdx++) {
                char followElement = rule[ruleIdx + 1];
            }
        }
    }
}