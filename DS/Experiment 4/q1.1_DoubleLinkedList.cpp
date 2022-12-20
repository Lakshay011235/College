/*
1.1. Write a program showing the implementation of Doubly linked list?
*/
#include <iostream>

class DoublyLinkedList {
private:
    // Definition for a node in the linked list
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;
    int size;
public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    // Insert a new node at the front of the list
    void insertAtBeginning(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == NULL) {
            tail = newNode;
        }
        size++;
    }

    // Insert a new node at the back of the list
    void insertAtEnd(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = tail;
        if (tail != NULL) {
            tail->next = newNode;
        }
        tail = newNode;
            if (head == NULL) {
        head = newNode;
        }
        size++;
    }

    // Remove the front node of the list
    void deleteAtBeginning() {
        if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        size--;
    }

    // Remove the back node of the list
    void deleteAtEnd() {
        if (tail == NULL) {
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        }
        delete temp;
        size--;
    }

    // Prints out the list
    friend std::ostream& operator<<(std::ostream& os, DoublyLinkedList& myList) {
        Node* temp = myList.head;
        while (temp != NULL) {
            std::cout << temp->data  << " -> ";
            temp = temp->next;
        }   
        return os << "";
    }
    // Check if the list is empty
    bool empty() {
        return size == 0;
    }
    };

int main() {
    DoublyLinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtBeginning(3);
    list.insertAtBeginning(4);
    std::cout << "Doubly Linked List :: \t" <<  list <<std::endl;

    list.deleteAtBeginning();
    list.deleteAtEnd();
    std::cout << "Doubly Linked List :: \t" <<  list <<std::endl;

    return 0;
}
