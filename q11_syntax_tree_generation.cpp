#include <bits/stdc++.h>
using namespace std;

vector<string> tree(50, "                              ");

void createSyntaxTree(string expression) {
    int row = 0, col = 2;
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            tree[row][col] = expression[i];
            tree[row + 1][col - 1] = '/';
            tree[row + 1][col + 1] = '\\';
            tree[row + 2][col - 2] = expression[i - 1];
            row += 2;
            col += 2;
        }
    }
    tree[row][col] = expression.back();
}

int main() {
    string expression;
    // Input format = A+B*C/D*G+F-T
    cin >> expression;
    createSyntaxTree(expression);
    cout << "Syntax Tree:\n";
    for (string x : tree) {
        cout << x << "\n";
    }
}
