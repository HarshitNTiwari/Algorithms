/*
Author: Harshit Tiwari
Date: 25-08-2022
https://www.codingninjas.com/codestudio/problems/check-if-two-trees-are-mirror_981176
*/

/*******************************************
  Following is the BinaryTreeNode structure

template<typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

********************************************/

bool areMirror(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    if (root1 == NULL || root2 == NULL)
        return root1 == root2;
    return (root1->data == root2->data) && areMirror(root1->left, root2->right) && areMirror(root1->right, root2->left);

}