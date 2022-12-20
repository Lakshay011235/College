/*
1. Write a program showing the implementation of Stack and Queue with array.
*/
#include <iostream>

const int MAX_SIZE = 100;

class Stack {
    private:
        int arr[MAX_SIZE];
        int top;

    public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int x) {
        if (isFull()) {
            std::cout << "Error: stack is full" << std::endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Error: stack is empty" << std::endl;
            return;
        }
        top--;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Error: stack is empty" << std::endl;
            return -1;
        }
        return arr[top];
    }
};
class Queue {
    private:
        int arr[MAX_SIZE];
        int front;
        int rear;

    public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front == rear+1;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            std::cout << "Error: queue is full" << std::endl;
            return;
        }
        rear++;
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
        std::cout << "Error: queue is empty" << std::endl;
        return;
        }
        front++;
    }

    int peek() {
        if (isEmpty()) {
        std::cout << "Error: queue is empty" << std::endl;
        return -1;
        }
        return arr[front];
    }
};  
int main() {
    std::cout << "-------------------STACK------------------" << std::endl;

    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << s.peek() << std::endl;  // Output: 3
    s.pop();
    std::cout << s.peek() << std::endl;  // Output: 2
    s.pop();
    std::cout << s.peek() << std::endl;  // Output: 1
    s.pop();
    s.pop();  // Error: stack is empty

    std::cout << std::endl << std::endl;
    std::cout << "-------------------QUEUE------------------" << std::endl;

    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    std::cout << q.peek() << std::endl;  // Output: 1
    q.dequeue();
    std::cout << q.peek() << std::endl;  // Output: 2
    q.dequeue();
    std::cout << q.peek() << std::endl;  // Output: 3
    q.dequeue();
    q.dequeue();  // Error: queue is empty

    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}
