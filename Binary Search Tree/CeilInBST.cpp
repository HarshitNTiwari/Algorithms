/*
Author: Harshit Tiwari
Date: 07-11-2022
https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
*/

int findCeil(struct Node* root, int input) {
	int ceil = -1;
	while (root != NULL) {
		if (root->data == input)
			return root->data;
		else if (root->data < input)
			root = root->right;
		else {
			ceil = root->data;
			root = root->left;
		}
	}
	return ceil;
}