#include <iostream>
using namespace std;

//Creating a class for the node
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    //Creating a constructor
    Node(int d){
        this -> data=d;
        this -> next=NULL;
        this -> prev=NULL;
    }
};

//Function to insert node at beginning
void InsertAtHead(Node* &head, int d){
    //Creating the node to be inserted
    Node* temp= new Node(d);
    //Updating the next and prev pointers
    temp->next=head;
    head->prev=temp;
    //Finally, updating the head pointer
    head=temp;
}

//Function to insert node at end   
void InsertAtTail(Node* &tail, int d){
    //Creating the node to be inserted
    Node* temp= new Node(d);
    //Updating the next and prev pointers
    temp->prev= tail;
    tail->next=temp;
    //Finally, updating the tail pointer
    tail=temp;
}

void InsertAtPosition(Node* &head, Node* &tail, int position, int d){
    //insert at beginning
    if(position==1){
        InsertAtHead(head,d);
        return;
    }
    //starting the traversal from the 1st node
    Node* temp = head;  
    int count=1;
    //Traverse the Linked List till Position-1
    while(count< position-1){
        temp=temp-> next;
        count++;
    }
    //Now temp will point to the node at 'position-1' place
    //If temp reaches the last node:
    if(temp->next==NULL){
        InsertAtTail(tail,d); //insert at end
        return;
    }
    //creating the node to be inserted
    Node* nodeToInsert = new Node(d);
    //Inserting this node after temp
    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    nodeToInsert->prev=temp;
    temp->next = nodeToInsert;
}

//Function to delete a node from the Linked List
void deleteNode(int position, Node* &head, Node* &tail){
    //Deleting the 1st node
    if(position==1){
        Node* temp = head;
        temp->next->prev=NULL;
        head=head->next; //head moved to the next node
        temp-> next = NULL;
        //free the space of temp
        delete temp;
    }
    else{           //deleting middle or last node
        //starting from the 1st node
        Node* current = head;
        Node* prev = NULL;
        int count = 1;
        //traversing till current reaches the position
        while(count < position){
            prev = current;
            current = current-> next;
            count++;
        }
        if(current->next==NULL){ //deleting last node
            tail=prev; //tail is moved to previous node
        }
        current->prev=NULL;
        prev->next = current-> next;
        current->next = NULL;
        //free the space of current node
        delete current;
    }
}