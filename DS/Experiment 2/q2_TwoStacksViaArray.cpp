/*
2. Write a program to implement two stacks using single array.
*/
#include <iostream>
#include <cstdlib>

using namespace std;

const int STACK_SIZE = 10;

class Stack {
private:
    int* arr;
    int top1, top2;

public:
    Stack() {
        arr = new int[STACK_SIZE];
        top1 = -1;
        top2 = STACK_SIZE;
    }

    ~Stack() {
        delete[] arr;
    }

    void push1(int value) {
        if (top1 + 1 == top2) {
            cout << "Error: stack overflow" << endl;
            return;
        }
        arr[++top1] = value;
    }

    void push2(int value) {
        if (top1 + 1 == top2) {
            cout << "Error: stack overflow" << endl;
            return;
        }
        arr[--top2] = value;
    }

    int pop1() {
        if (top1 < 0) {
            cout << "Error: stack underflow" << endl;
            exit(EXIT_FAILURE);
        }
        return arr[top1--];
    }

    int pop2() {
        if (top2 > STACK_SIZE - 1) {
            cout << "Error: stack underflow" << endl;
            exit(EXIT_FAILURE);
        }
        return arr[top2++];
    }
};

int main() {
    Stack stack;
    stack.push1(1);
    stack.push1(2);
    stack.push2(3);
    stack.push2(4);

    cout << stack.pop1() << endl;
    cout << stack.pop1() << endl;
    cout << stack.pop2() << endl;
    cout << stack.pop2() << endl;

    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}
