#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> PN = {"Sagor", "Selim", "Salma", "Nipu"};
    set<string> P = {"he", "she", "I", "we", "you", "they"};
    set<string> N = {"book", "cow", "dog", "home", "grass", "rice", "mango"};
    set<string> V = {"read", "eat", "take", "run", "write"};

    string currentWord;
    int currentWordIdx = 0;
    while (cin >> currentWord) {
        if (currentWordIdx == 0 && !PN.count(currentWord) && !P.count(currentWord)) {
            cout << "Invalid";  // if the first word is not a proper noun or a pronoun
            return 0;
        } else if (currentWordIdx == 1 && !V.count(currentWord)) {
            cout << "Invalid";  // if the second word is not a verb
            return 0;
        } else if (currentWordIdx == 2 && !N.count(currentWord)) {
            cout << "Invalid";  // if the third word is not a noun
            return 0;
        }
        currentWordIdx++;
    }
    if (currentWordIdx == 3 || currentWordIdx == 2) {
        cout << "Valid";
    } else {
        cout << "Invalid";  // if the sentence is too short or too long
    }

    return 0;
}