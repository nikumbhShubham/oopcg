#include <iostream>
#include <cstring>
using namespace std;
class stack
{
public:
    char *arr;
    int capacity;
    int top;

    stack(int size)
    {
        capacity = size;
        arr = new char(capacity);
        top = -1;
    }
    ~stack()
    {
        delete[] arr;
    }
    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == capacity - 1);
    }

    void push(char val)
    {
        if (isFull())
        {
            std::cout << "Stack Overflow: Cannot push more elements." << std::endl;
            return;
        }
        arr[++top] = val;
    }

    char pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack Underflow: Cannot pop from an empty stack." << std::endl;
            return '\0';
        }
        return arr[top--];
    }

    char peek()
    {
        if (isEmpty())
        {
            return '\0';
        }
        return arr[top];
    }
};

bool palindrome(char *str)
{
    int len = strlen(str);
    stack st(len);
    int i;
    for (i = 0; i < len; i++)
    {
        if (isalnum(str[i]))
        {    st.push(tolower(str[i]));
        }
    }

    for (i = 0; i < len; i++)
    {
        if (isalnum(str[i])){
        if (tolower(str[i]) != st.pop())
        {
            return false;
        }
    }
    }

    return true;
}

int main()
{
    const int MAXS = 100;
    char input[MAXS];

    cout << "enter string:\n";
    cin.getline(input, MAXS);
    if (palindrome(input))
    {
        cout << "the srting is palindrome";
    }
    else
    {
        cout << "the string is not palindrome";
    }

    return 0;
}