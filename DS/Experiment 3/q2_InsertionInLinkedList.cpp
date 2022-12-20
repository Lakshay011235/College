/*
2. Write a program for the insertion (at beginning,end and any position) in a Linked list.
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

    void insertAtIndex(int value, int index){
        if (index == 0) insertAtBeginning(value);
        else if ((index == list_length-1) || ( index == -1))    insertAtEnd(value);
        else{
            Node* temp = head;
            for (int i = 0; i < index-1; i++) temp = temp->next;
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
        }
        list_length++;
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
    l1.insertAtBeginning(1);    //  1
    std::cout << "insertAtBeginning(1) Linked List :: \t" << l1 << std::endl;
    l1.insertAtBeginning(2);    //  2 -> 1 
    std::cout << "insertAtBeginning(2) Linked List :: \t" << l1 << std::endl;
    
    l1.insertAtEnd(3);          //  2 -> 1 -> 3
    std::cout << "insertAtEnd(3) Linked List :: \t\t" << l1 << std::endl;
    l1.insertAtEnd(4);          //  2 -> 1 -> 3 -> 4
    std::cout << "insertAtEnd(4) Linked List :: \t\t" << l1 << std::endl;
    
    l1.insertAtIndex(5,0);      //  5 -> 2 -> 1 -> 3 -> 4
    std::cout << "insertAtIndex(5,0) Linked List :: \t" << l1 << std::endl;
    
    l1.insertAtIndex(6,3);      //  5 -> 2 -> 1 -> 3 -> 4
    std::cout << "insertAtIndex(6,3) Linked List :: \t" << l1 << std::endl;
    
    l1.insertAtIndex(7,-1);      //  5 -> 2 -> 1 -> 3 -> 4
    std::cout << "insertAtIndex(7,-1) Linked List :: \t" << l1 << std::endl;

    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}

