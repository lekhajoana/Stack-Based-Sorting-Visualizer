#include <iostream>
#include <stack>
using namespace std;

// Function to sort a stack using another stack
void sortStack(stack<int>& s) {
    stack<int> temp;

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        // Move elements from temp back to s if they are greater
        while (!temp.empty() && temp.top() > current) {
            s.push(temp.top());
            temp.pop();
        }

        temp.push(current);
    }

    // Transfer sorted elements back to original stack
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
}

// Function to print stack (top to bottom)
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;

    // Example input
    s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);

    cout << "Original stack:\n";
    printStack(s);

    sortStack(s);

    cout << "Sorted stack (ascending, top is smallest):\n";
    printStack(s);

    return 0;
}