#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// Binary Tree Definition
struct Node{
    int key;  //data
    struct Node *left; //left pointer
    struct Node *right; //right pointer
    Node(int k){   //constructor
        key = k;   //key is initialized with passed parameter
        left=right=NULL;  //left and right pointers are made NULL
    }
};

// --------------Function Prototypes------------------

void inorder_traverse(Node *root);
void preorder_traverse(Node *root);
void postorder_traverse(Node *root);
int height(Node *root);
void k_distance(int k, Node *root);
void level_order(Node *root);
void levelorder_traversal(Node *root);
void levelOrder_LineByLine(Node *root);
void levelOrder_LineByLine_2(Node *root);
int size_tree(Node *root);

int main(){
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> left ->left =new Node(40);
    // inorder_traverse(root); cout<<endl;
    // preorder_traverse(root); cout<<endl;
    // postorder_traverse(root); cout<<endl;
    // cout<<height(root)<<endl;
    // k_distance(0, root);
    // level_order(root);
    // levelorder_traversal(root);
    // levelOrder_LineByLine(root);
    // levelOrder_LineByLine_2(root);
    std::cout<<size_tree(root)<<endl; 
    return 0;
}

//-------Depth First Traversal-----------

//Inorder Traversal (Left-Root-Right)
void inorder_traverse(Node *root){
    if(root!=NULL){
        inorder_traverse(root->left);
        std::cout<<root->key<<" ";
        inorder_traverse(root->right);
    }
    return;
}

//Preorder Traversal (Root-Left-Right)
void preorder_traverse(Node *root){
    if(root!=NULL){
        std::cout<<root->key<<" ";
        preorder_traverse(root->left);
        preorder_traverse(root->right);
    }
    return;
}

//Postorder Traversal (Left-Right-Root)
void postorder_traverse(Node *root){
    if(root!=NULL){
        postorder_traverse(root->left);
        postorder_traverse(root->right);
        std::cout<<root->key<<" ";
    }
    return;
}

//Height of the binary tree  (TC: O(n))
int height(Node *root){
    if(root==NULL)
        return 0;
    return max(height(root->left), height(root->right))+1;
}

// Print Nodes at a distance k from root (TC: O(n))
void k_distance(int k, Node *root){
    if(root!=NULL){
        if(k==0)
            cout<<root->key<<" ";
        k_distance(k-1, root->left);
        k_distance(k-1, root->right);
    }
    return;
}

// ----------Breadth first Traversal---------


//Level order Traversal   TC: O(h*n)
void level_order(Node *root){
    if(root!=NULL){
        int h= height(root);     //TC: O(n)
        for(int k=0;k<h;k++){    // TC of this loop: Theta(h)
            k_distance(k, root);    //TC: O(n)
        }
    }
    return;
}

// Level Order Traversal using Queue (TC: O(n))
void levelorder_traversal(Node *root){
    if(root!=NULL){
        queue<Node*> q;
        q.push(root);
        while(q.empty()==false){
            Node *currNode = q.front();
            cout<<currNode->key<<" ";   
            q.pop();     
            if(currNode->left!=NULL)
                q.push(currNode->left);
            if(currNode->right!=NULL)
                q.push(currNode->right);
        }
    }
    return;
}

// Printing Level Order Traversal Line By Line ------Method 1 (TC:O(n))
void levelOrder_LineByLine(Node *root){
    if(root!=NULL){
        queue<Node*> q;
        q.push(root);
        while(q.empty()==false){
            int len = q.size();
            for(int i=0;i<len;i++){       //using additional loop
                Node *currNode = q.front();
                cout<<currNode->key<<" ";
                q.pop();     
                if(currNode->left!=NULL)
                    q.push(currNode->left);
                if(currNode->right!=NULL)
                    q.push(currNode->right);
            }
            cout<<endl;   //printing new line
        }
    }
    return;
}

// Printing Level Order Traversal Line By Line -----Method 2 (TC: O(n))
void levelOrder_LineByLine_2(Node *root){
    if(root!=NULL){
        queue<Node *> q;
        q.push(root);
        q.push(NULL);  //pushing an additional NULL to mark end of a level
        while(q.size()>1){
            Node *currNode = q.front();
            q.pop();
            if(currNode==NULL){ //When NULL is encountered that means we've reached end of current level
                cout<<endl;  //so we print new line
                q.push(NULL); //when end of current level is reahced, it means that all the children of current level have already been   
                continue;         //pushed into the queue. So, we push another NULL which will mark the end of the next level
            }
            cout<<currNode->key<<" ";
            if(currNode->left!=NULL)
                q.push(currNode->left);
            if(currNode->right!=NULL)
                q.push(currNode->right);
        }
    }
    return;
}

//Size of the Binary Tree
int size_tree(Node *root){
    int size=0;
    if(root!=NULL){
        size = size_tree(root->left)+size_tree(root->right)+1;
    }
    return size;
}