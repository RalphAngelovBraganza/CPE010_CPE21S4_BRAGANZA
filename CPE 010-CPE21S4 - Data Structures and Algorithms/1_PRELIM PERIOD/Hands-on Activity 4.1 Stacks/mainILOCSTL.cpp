#include <iostream>
#include <stack>
#include <string>

// Function to check if the opening and closing symbols match
bool checkPair(char open, char close) {

    if (open == '(' && close == ')')
        return true;

    if (open == '[' && close == ']')
        return true;

    if (open == '{' && close == '}')
        return true;

    // Symbols do not match
    return false;
}

// Function to check if an expression is balanced
bool checkBalance(std::string exp) {

    // Create a stack to store opening symbols
    std::stack<char> st;

    // Read each character in the expression
    for (int i = 0; i < exp.length(); i++) {

        char ch = exp[i];

        // If the character is an opening symbol, push it onto the stack
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        }

        // If the character is a closing symbol
        else if (ch == ')' || ch == ']' || ch == '}') {

            // If the stack is empty, there is no matching opening symbol
            if (st.empty()) {
                return false;
            }

            // Get the top opening symbol
            char temp = st.top();

            // Remove it from the stack
            st.pop();

            // Check if the symbols match
            if (!checkPair(temp, ch)) {
                return false;
            }
        }

        // Ignore letters, numbers, operators, and spaces
    }

    // If the stack is empty, all symbols were matched
    if (st.empty())
        return true;
    else
        return false;
}

int main() {

    // Variable to store the user's expression
    std::string exp;

    // Ask the user for an expression
    std::cout << "-------SYMBOL BALANCER (OPTIONAL VERSION)-------\n";
    std::cout << "Enter an expression: ";
    std::getline(std::cin, exp);

    // Check if the expression is balanced
    if (checkBalance(exp))
        std::cout << "\nExpression is VALID.\n";
    else
        std::cout << "\nExpression is INVALID.\n";

    return 0;
}

