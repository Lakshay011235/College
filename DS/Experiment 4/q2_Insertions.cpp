/*
2. Write a program for the insertion (at beginning,end and any position) in a Doubly and Circular linked list.
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

    void insertAtPos(int pos, int data) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (pos == 0) {
            insertAtBeginning(data);
            return;
        }

        Node *temp = head;
        int i = 0;
        while (i < pos - 1 && temp->next != NULL) {
            temp = temp->next;
            i++;
        }

        if (temp->next == NULL) {
            std::cout << "Invalid position!" << std::endl;
        } 
        else {
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }
    // Prints out the list
    friend std::ostream& operator<<(std::ostream& os, DoublyLinkedList& myList) {
        Node* temp = myList.head;
        while (temp != NULL) {
            std::cout << temp->data << " " << char(29) << " ";
            temp = temp->next;
        }   
        return os << "";
    }
    // Check if the list is empty
    bool empty() {
        return size == 0;
    }
};

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node *next;
    };
    Node *head; 
public:
    CircularLinkedList() {
        head = NULL;
    }
    void insertAtEnd(int data) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } 
        else {
            Node *temp = head;
            while (temp->next != head) {
            temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertAtBegin(int data) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } 
        else {
            Node *temp = head;
            while (temp->next != head) {
            temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtPos(int pos, int data) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (pos == 0) {
            insertAtBegin(data);
            return;
        }

        Node *temp = head;
        int i = 0;
        while (i < pos - 1 && temp->next != head) {
            temp = temp->next;
            i++;
        }

        if (temp->next == head) {
            std::cout << "Invalid position!" << std::endl;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Prints out the list
    friend std::ostream& operator<<(std::ostream& os, CircularLinkedList& myList) {
        Node* temp = myList.head;
        while (temp->next != myList.head) {
            std::cout << temp->data  << " " << char(29) << " ";
            temp = temp->next;
        }   
        return os << temp->data;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtEnd(1);
    std::cout << "< insert at end = 1 > Doubly Linked List :: \t\t" <<  list <<std::endl;

    list.insertAtEnd(2);
    std::cout << "< insert at end = 2 > Doubly Linked List :: \t\t" <<  list <<std::endl;

    list.insertAtBeginning(3);
    std::cout << "< insert at begin = 3 > Doubly Linked List :: \t\t" <<  list <<std::endl;

    list.insertAtBeginning(4);
    std::cout << "< insert at begin = 4 > Doubly Linked List :: \t\t" <<  list <<std::endl;

    list.insertAtPos(2, 5);
    std::cout << "< insert at pos(2) = 5 > Doubly Linked List :: \t\t" <<  list <<std::endl << std::endl;
        
    CircularLinkedList clist;
    clist.insertAtEnd(11);
    std::cout << "< insert at end = 1 > Circular Linked List :: \t\t" <<  clist <<std::endl;

    clist.insertAtEnd(12);
    std::cout << "< insert at end = 2 > Circular Linked List :: \t\t" <<  clist <<std::endl;

    clist.insertAtBegin(13);
    std::cout << "< insert at begin = 3 > Circular Linked List :: \t" <<  clist <<std::endl;

    clist.insertAtBegin(14);
    std::cout << "< insert at begin = 4 > Circular Linked List :: \t" <<  clist <<std::endl;

    clist.insertAtPos(2, 15);
    std::cout << "< insert at pos(2) = 5 > Circular Linked List :: \t" <<  clist <<std::endl;
    
    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}
