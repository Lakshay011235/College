/*
2. Write a program for the deletion (at beginning,end and any position) in a Linked list.
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

    void deleteAtBeginning(){
        if(list_length != 0){
        Node* temp = head;
        head = head->next; 
        delete temp;
        list_length--;
        }
        else std::cout << "List is empty" << std::endl;
    }
    
    void deleteAtEnd(){
        if(list_length != 0){
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        list_length--;
        }
        else std::cout << "List is empty" << std::endl;
    }
    void deleteAtIndex(int index){
        if(list_length != 0){
            if (index == 0) deleteAtBeginning();
            else if ((index == list_length-1) || ( index == -1))    deleteAtEnd();
            else{
                Node* temp = head;
                for (int i = 0; i < index-1; i++) temp = temp->next;
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete(toDelete);
            }
            list_length--;
        }
        else std::cout << "List is empty" << std::endl;
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
    std::cout << "Linked List :: \t\t\t\t" << l1 << std::endl;

    l1.deleteAtBeginning();     //  2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    std::cout << "deleteAtBeginning() Linked List :: \t" << l1 << std::endl;

    l1.deleteAtEnd();           //  2 -> 3 -> 4 -> 5 -> 6 -> 7
    std::cout << "deleteAtEnd() Linked List :: \t\t" << l1 << std::endl;
    
    l1.deleteAtIndex(0);        //  3 -> 4 -> 5 -> 6 -> 7
    std::cout << "deleteAtIndex(0) Linked List :: \t" << l1 << std::endl;
    
    l1.deleteAtIndex(3);        //  3 -> 4 -> 5 -> 7
    std::cout << "deleteAtIndex(3) Linked List :: \t" << l1 << std::endl;
    
    l1.deleteAtIndex(-1);       //  3 -> 4 -> 5 
    std::cout << "deleteAtIndex(-1) Linked List :: \t" << l1 << std::endl;

    std::cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}

