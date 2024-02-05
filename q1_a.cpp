#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    istringstream iss(input);
    string token;

    // count number of words
    int wordCount = 0;
    while (iss >> token) {
        wordCount++;
    }
    cout << "Number of words: " << wordCount << endl;

    // count number of letters, digits, and other characters
    int letterCount = 0;
    int digitCount = 0;
    int otherCharacterCount = 0;
    for (char c : input) {
        if (isalpha(c)) {
            letterCount++;
        } else if (isdigit(c)) {
            digitCount++;
        } else if (!isspace(c)) {
            otherCharacterCount++;
        }
    }
    cout << "Number of letters: " << letterCount << endl;
    cout << "Number of digits: " << digitCount << endl;
    cout << "Number of other characters: " << otherCharacterCount << endl;

    return 0;
}