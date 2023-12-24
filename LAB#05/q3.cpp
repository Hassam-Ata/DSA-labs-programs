#include <iostream>
#include <stack>
using namespace std;

string getOriginalString(string& input) {
    stack<char> Stack1, Stack2;

    for (char ch : input) {
        Stack1.push(ch);
    }

    while (!Stack1.empty()) {
        Stack2.push(Stack1.top());
        Stack1.pop();
    }

    string reversedString;

    while (!Stack2.empty()) {
        reversedString += Stack2.top();
        Stack2.pop();
    }

    return reversedString;
}

int main() {
    string input = "data Structure";
    string originalString = getOriginalString(input);

    cout << "Input: " << input << endl;
    cout << "Output: " << originalString << endl;

    return 0;
}
