/*
3. Write a program for the deletion (at beginning,end and any position) in a Doubly and Circular linked list.
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

    void deleteAtPos(int pos) {
        Node *temp = head;
        if (pos == 0) { deleteAtBeginning(); return;}
        int i = 0;
        while (i < pos && temp->next != NULL) {
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL) {
            std::cout << "Invalid position!" << std::endl;
        } 
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

    // Prints out the list
    friend std::ostream& operator<<(std::ostream& os, DoublyLinkedList& myList) {
        Node* temp = myList.head;
        while (temp != NULL) {
            std::cout << temp->data  << " " << char(29) << " ";
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
    void deleteAtEnd() {
        Node *temp = head;
        Node *prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
    }

    void deleteAtBegin() {
        Node *temp = head;
        Node *prev = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        delete prev;
        head = temp->next;
    }

    void deleteAtPos(int pos) {
        Node *temp = head;
        Node *prev = NULL;
        if (pos == 0) { deleteAtBegin(); return; };

        int i = 0;
        while (i < pos && temp->next != head) {
            prev = temp;
            temp = temp->next;
            i++;
        }
        if (temp->next == head) {
            std::cout << "Invalid position!" << std::endl;
        } else {
            prev->next = temp->next;
            delete temp;
        }
    }
    // Prints out the list
    friend std::ostream& operator<<(std::ostream& os, CircularLinkedList& myList) {
        Node* temp = myList.head;
        while (temp->next != myList.head) {
            std::cout << temp->data  << " -> ";
            temp = temp->next;
        }   
        return os << temp->data;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    std::cout << "< inserted 1,2,3,4,5 > Doubly Linked List :: \t" <<  list <<std::endl;

    list.deleteAtEnd();
    std::cout << "< delete at end > Doubly Linked List :: \t" <<  list <<std::endl;
    
    list.deleteAtBeginning();
    std::cout << "< delete at begin > Doubly Linked List :: \t" <<  list <<std::endl;

    list.deleteAtPos(1);
    std::cout << "< delete at pos=1 > Doubly Linked List :: \t" <<  list <<std::endl << std::endl;

    CircularLinkedList clist;

    clist.insertAtEnd(1);
    clist.insertAtEnd(2);
    clist.insertAtEnd(3);
    clist.insertAtEnd(4);
    clist.insertAtEnd(5);
    std::cout << "< inserted 1,2,3,4,5 > Circular Linked List :: \t" <<  clist <<std::endl;

    clist.deleteAtEnd();
    std::cout << "< delete at end > Circular Linked List :: \t" <<  clist <<std::endl;
    
    clist.deleteAtBegin();
    std::cout << "< delete at begin > Circular Linked List :: \t" <<  clist <<std::endl;

    clist.deleteAtPos(1);
    std::cout << "< delete at pos=1 > Circular Linked List :: \t" <<  clist <<std::endl;

    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}
