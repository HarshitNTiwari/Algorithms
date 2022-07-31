#include <iostream>
using namespace std;

//Creating a class for the node
class Node{
public:
    int data;
    Node* next;

    // Creating a constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        std::cout << " memory is free for node with data " << value << std::endl;
    }
};

//Function to insert a node at given position in the Linked List
void InsertAtPosition(int position, int d, Node* &head, Node* &tail){
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
    temp->next = nodeToInsert;
}

void InsertAtTail(Node* &tail, int d){
    //Creating a new node
    Node* temp = new Node(d);
    //Placing this node after the last node
    //i.e. at the end of the Linked List
    tail-> next= temp;
    tail=temp;
}

void InsertAtHead(Node* &head, int d){

    //Creating a new node
    Node* temp = new Node(d);
    //Placing this node before the 1st node
    //i.e. at the beginning of the Linked List
    temp -> next = head; 
    head = temp;
}

void print(Node* &head){
    Node* temp= head; //starting from the 1st node

    //until we reach the last node
    while(temp!=NULL){  
        //printing the data of the current node
        cout<< temp-> data<<endl;
        //Moving to the next node
        temp = temp->next;
    }
}

//Function to delete a node from the Linked List
void deleteNode(int position, Node* &head, Node* &tail){
    //Deleting the 1st node
    if(position==1){
        Node* temp = head;
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
        prev->next = current-> next;
        current->next = NULL;
        //free the space of current node
        delete current;
    }
}


// Function to find length of a Linked List : O(n)
int getLength(Node* head){
    int len=0; //to store the length 
    //Traversing the entire Linked List
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}

int main(){

    //Creating an object of Node class;
    Node* node1 = new Node(10);

    //Printing the values of data and next pointer 
    std::cout<< node1 -> data <<std::endl;
    std::cout<< node1 -> next <<std::endl;

    //head pointed to node1
    Node* head = node1;

    return 0;
}