#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {}

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        if (q1.empty()) return -1;
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    cout << myStack.top() << endl; // Output: 3
    cout << myStack.pop() << endl; // Output: 3
    cout << myStack.top() << endl; // Output: 2
    cout << myStack.empty() << endl; // Output: 0 (false)
    return 0;
}
