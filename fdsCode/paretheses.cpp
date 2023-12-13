#include <iostream>
#include<cstring>
class Stack {
private:
    int maxSize;
    int top;
    char* stackArray;

public:
    Stack(int size) {
        maxSize = size;
        stackArray = new char[maxSize];
        top = -1;
    }

    ~Stack() {
        delete[] stackArray;
    }

    void push(char c) {
        if (top == maxSize - 1) {
            std::cout << "Stack overflow\n";
            return;
        }
        stackArray[++top] = c;
    }

    char pop() {
        if (top == -1) {
            std::cout << "Stack underflow\n";
            return '\0';
        }
        return stackArray[top--];
    }

    bool isEmpty() {
        return (top == -1);
    }
};

bool isBalanced(const std::string& expression) {
    Stack stack(expression.length());
    // int count=strlen(expression);
    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.isEmpty()) {
                return false;
            } else {
                char popped = stack.pop();
                if ((c == ')' && popped != '(') ||
                    (c == ']' && popped != '[') ||
                    (c == '}' && popped != '{')) {
                    return false;
                }
            }
        }
    }

    return stack.isEmpty();
}

int main() {
    std::string expression;
    std::cout << "Enter a string with parentheses: ";
    std::cin >> expression;

    if (isBalanced(expression)) {
        std::cout << "The string has balanced parentheses.\n";
    } else {
        std::cout << "The string does not have balanced parentheses.\n";
    }

    return 0;
}
