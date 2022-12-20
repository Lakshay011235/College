/*
4. Write a program for the reverse of a Linked list.
*/
#include <iostream>

struct Node
{   
    int data;
    Node* next;
};
 
class LinkedList
{
private:
    Node* head;
    int list_length;
public:
    LinkedList() {
        head = NULL;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    void insertAtBeginning(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        list_length++;
    }

    void insertAtEnd(int value){
        if (head == NULL) {insertAtBeginning(value); return;};
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        temp->next = newNode;
        list_length++;
    }
    void reverse() {
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    friend std::ostream& operator<<(std::ostream& os, LinkedList& myList) {
        Node* temp = myList.head;
        while (temp != NULL) {
            std::cout << temp->data  << " -> ";
            temp = temp->next;
        }   
        return os << "";
    }
};
int main()
{
    LinkedList l1;
    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    l1.insertAtEnd(4);
    l1.insertAtEnd(5);
    l1.insertAtEnd(6);
    l1.insertAtEnd(7);
    l1.insertAtEnd(8);

    //1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    std::cout << "Linked List :: \t\t" << l1 << std::endl;

    l1.reverse();    // 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1
    std::cout << "Reverse Linked List :: \t" << l1 << std::endl;


    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}

