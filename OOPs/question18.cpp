/*
Create  a  class  called  LIST  with  two  pure  virtual  function  store()  and  retrieve().To  store  a  value  call store and to retrieve call retrieve function. Derive two classes stack and queue from it and override store and retrieve.
*/
#include <iostream>

using namespace std;

// List class with pure virtual functions store and retrieve
class List {
public:
    virtual void store(int value) = 0;
    virtual int retrieve() = 0;
};

// Stack class derived from List
class Stack: public List {
private:
    int data[10];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Override store function to push value onto stack
    void store(int value) {
        data[++top] = value;
    }

    // Override retrieve function to pop value from stack
    int retrieve() {
        return data[top--];
    }
};

// Queue class derived from List
class Queue: public List {
private:
    int data[10];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    // Override store function to insert value into queue
    void store(int value) {
        if (rear == 9) {
            cout << "Queue is full" << endl;
        } else {
            data[++rear] = value;
        }
    }

    // Override retrieve function to remove value from queue
    int retrieve() {
        if (front == rear) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            return data[++front];
        }
    }
};

int main() {
    // Create stack and queue objects
    Stack stack;
    Queue queue;

    // Store and retrieve values from stack and queue
    stack.store(1);
    stack.store(2);
    cout << "Stack: " << stack.retrieve() << " " << stack.retrieve() << endl;

    queue.store(3);
    queue.store(4);
    cout << "Queue: " << queue.retrieve() << " " << queue.retrieve() << endl;

    std::cout << "Written By :> Lakshay Sharma :: 02396402721";
    return 0;
}
