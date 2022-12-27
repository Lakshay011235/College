/*
4. Write a program for the reverse of a Doubly and Circular linked list.
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

    void reverse(){
        Node* temp = head;
        Node* tempp = head->prev;
        Node* tempn = head->next;

        while (temp->next != NULL){
            temp = temp->next;
            tempp = temp->prev->prev;
            tempn = temp;
            temp->prev->next = tempp;
            temp->prev->prev = tempn;
        }
        tempp = temp->prev;
        tempn = temp->next;
        temp->next = tempp;
        temp->prev = tempn;
        head = temp;
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
    void reverse() {
        if(head != NULL) {
            Node* prev = head;
            Node* temp = head;
            Node* curr = head->next;
            prev->next = prev;
            
            while(curr != head) {
                temp = curr->next;
                curr->next = prev;
                head->next = curr;
                prev = curr;
                curr = temp;
            }
            head = prev;
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
int main(){
    DoublyLinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    std::cout << "< original > Doubly Linked List :: \t" <<  list <<std::endl;

    list.reverse();    
    std::cout << "< reversed > Doubly Linked List :: \t" <<  list <<std::endl << std::endl;

    CircularLinkedList clist;

    clist.insertAtEnd(1);
    clist.insertAtEnd(2);
    clist.insertAtEnd(3);
    clist.insertAtEnd(4);
    clist.insertAtEnd(5);

    std::cout << "< original > Circular Linked List :: \t" <<  clist <<std::endl;

    clist.reverse();    
    std::cout << "< original > Circular Linked List :: \t" <<  clist <<std::endl;

    std::cout << "\nWritten By: Lakshay Sharma 02396402721";

    return 0;
}