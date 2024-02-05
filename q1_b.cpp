#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    istringstream iss(input);
    string token;

    // separate words, digits, and other characters
    vector<string> words;
    vector<char> letters;
    vector<char> digits;
    vector<char> otherCharacters;
    while (iss >> token) {
        words.push_back(token);
    }
    for (char c : input) {
        if (isalpha(c)) {
            letters.push_back(c);
        } else if (isdigit(c)) {
            digits.push_back(c);
        } else if (!isspace(c)) {
            otherCharacters.push_back(c);
        }
    }

    // print the results
    cout << "Number of words: " << words.size() << endl;
    cout << "Number of letters: " << letters.size() << endl;
    cout << "Number of digits: " << digits.size() << endl;
    cout << "Number of other characters: " << otherCharacters.size() << endl;

    return 0;
}