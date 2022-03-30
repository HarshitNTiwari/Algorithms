#include <iostream>
using namespace std;

//Creating a class for the node
class Node{
    public:
    int data;
    Node* next;

    // Creating a constructor
    Node(int data){
        this -> data=data;
        this -> next=NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
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

//Recursive function to reverse a Linked List
//It will return head of the reversed Linked List
Node* reverse1(Node* &head){
    //base condition: either the list is empty or 
    //the list contains just a single node 
    if(head==NULL || head->next==NULL){
        return head;
    }

    // newHead is the head pointer of the smaller 
    // reversed list
    Node* newHead= reverse1(head->next); 
    head->next->next=head;
    head->next=NULL;

    return newHead;
}

//Recursive function to reverse a Linked List
void reverse(Node* &head, Node* current, Node* prev){
    //base condition: when current pointer reaches 
    //the last node
    if(current==NULL){
        head=prev;
        return;
    }
    //Forward pointer to preserve the remaining Linked List
    Node* Forward= current-> next;
    //Reverse the remaining Linked list by recursive call
    reverse(head,Forward,current);
    //Reverse the current node;
    current->next=prev;
}


//Iterative function to reverse a Linked List
Node* reverseLinkedList(Node* &head){
    //if Linked List is empty or there's just 1 node
    //we simply return that node
    if(head==NULL || head->next==NULL)
        return head;

    Node* prev = NULL;
    Node* current = head;
    
    //traversing till we reach the last node
    while(current!=NULL){
        //Forward pointer to preserve the remaining Linked List
        Node* forward = current->next;
        current->next = prev;
        //updating the previous and current pointers
        prev = current;
        current = forward;
    }
    head=prev;
    return prev;
}
// Function to find length of a Linked List
int getLength(Node* head){
    int len=0; //to store the length 
    //Traversing the entire Linked List
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}

// Function to return middle node
Node* findMiddle(Node* head){
    int len= getLength(head);
    //Position of middle node
    int middle= (len/2)+1; 
    Node* temp= head;
    int cnt=1;
    // traversing till middle node is reached
    while(cnt<middle){
        temp=temp->next;
        cnt++;
    }
    return temp;
}

// Function to return middle node
Node* getMiddle(Node* head){
    //If Linked List is empty or 
    // contains a single node
    if(head==NULL || head->next==NULL)
        return head;
    // Linked List comtains 2 nodes
    // return the 2nd node 
    if(head->next->next==NULL)
        return head->next;

    Node* slow=head;
    Node* fast=head->next;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL)
            fast=fast->next;
        slow=slow->next;
    }
    return slow;
}


int main(){

    //Creating an object of Node class;
    Node* node1 = new Node(10);

    //Printing the values of data and next pointer 
    cout<< node1 -> data <<endl;
    cout<< node1 -> next <<endl;

    //head pointed to node1
    Node* head = node1;

    return 0;
}