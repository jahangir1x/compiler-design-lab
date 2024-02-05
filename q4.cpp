#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    string input;
    cin >> input;
    // check if integer variable
    if (regex_match(input, regex("[i-nI-N][a-zA-Z0-9]*"))) {
        cout << "Valid integer variable" << endl;
    }

    // check if shortInt Number
    if (regex_match(input, regex("[1-9]|[1-9][0-9]|[1-9][0-9][0-9]|[1-9][0-9][0-9][0-9]"))) {
        cout << "Valid shortInt number" << endl;
    }

    // check if longInt Number
    if (regex_match(input, regex("[1-9][0-9][0-9][0-9][0-9]+"))) {
        cout << "Valid longInt number" << endl;
    }

    return 0;
}