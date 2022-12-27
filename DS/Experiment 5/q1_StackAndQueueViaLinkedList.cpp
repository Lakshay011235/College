/*
1. Write a program showing the implementation of Stack and Queue with Linked list.
*/
#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Stack class with push, pop, and peek operations
class Stack {
private:
    Node* top;

public:
    Stack() { top = NULL; }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = top;

        // Set the new node as the top of the stack
        top = newNode;
    }

    int pop() {
        // Return -1 if the stack is empty
        if (top == NULL) return -1;
        int data = top->data;
        
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    int peek() {
        // Return -1 if the stack is empty
        if (top == NULL) return -1;
        return top->data;
    }
};

// Queue class with enqueue, dequeue, and peek operations
class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() { head = tail = NULL; }

    void enqueue(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        // If the queue is empty, set the new node as both the head and tail
        if (tail == NULL) {
            head = tail = newNode;
        }
        // Otherwise, set the new node as the tail and update the tail pointer
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int dequeue() {
        // Return -1 if the queue is empty
        if (head == NULL) return -1;

        int data = head->data;
        Node* temp = head;
        head = head->next;

        // If the head is now null, set the tail to be null as well (queue is empty)
        if (head == NULL) tail = NULL;

        delete temp;
        return data;
    }

    int peek() {
        // Return -1 if the queue is empty
        if (head == nullptr) return -1;
        return head->data;
    }
};

int main() {
    // Create a stack and push some values onto it
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // Pop and print the values from the stack
    std::cout << "Stack :: " ;
    std::cout << stack.pop() << " ";
    std::cout << stack.pop() << " ";
    std::cout << stack.pop() << std::endl << std::endl;

    // Create a queue and enqueue some values
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    // Dequeue and print the values from the queue
    std::cout << "Queue :: " ;
    std::cout << queue.dequeue() << " ";
    std::cout << queue.dequeue() << " ";
    std::cout << queue.dequeue() << std::endl;

    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}