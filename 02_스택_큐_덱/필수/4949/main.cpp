#include <iostream>
#include <stack>
#include<string>
using namespace std;

int main() {

    string str;
    while (true){
        getline(cin, str);
        if(str == ".") {
            break;
        }
        stack<char> s;
        bool isBalanced = true;
        for(char c : str) {
            if (c == '(' || c == '[') {
                s.push(c);
            }
            else if (c == ')') {
                if(s.empty() == false && (s.top() == '(')) {
                    s.pop();
                }
                else {
                    isBalanced = false;
                    break;
                }
            }
            else if(c == ']') {
                if (s.empty() == false && (s.top() == '[')) {
                    s.pop();
                }
                else {
                    isBalanced = false;
                    break;
                }
            }
        }
        if(s.empty() && isBalanced == true) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
    return 0;
}
