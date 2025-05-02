#include <iostream>

using namespace std;

// Implement the node class we will need for our Binary Search Tree
class Node {
	public:
		// the Node should contain
		// 	- an integer "key" that holds the value of the Node
		// 	- a pointer to each child possible child node ("right" and "left")
		int key;
		Node* right;
		Node* left;

		// Write a constructor for the Node
		// input: only an integer value for "key", no pointer arguments
		// 		right and left pointers should be null
		Node(int val) : key(val), left(nullptr), right(nullptr) {};

};


// Use this function to create a Binary Search Tree (BST) tree with the following values
// {13, 0, 7, 6, 21, 15, -2, 12, 99, 18, 19, -1}
Node* createTree() {
	// root
	Node *root = new Node(13);

	// level 1 (children of root)
	root->left = new Node(0);
	root->right = new Node(21);

	// level 2 (children of 0)
	root->left->left = new Node(-2);
	root->left->right = new Node(7);

	// level 2 (children of 21)
	root->right->left = new Node(15);
	root->right->right = new Node(99);

	// level 3 (children of -2)
	root->left->left->left = new Node(-1);

	// level 3 (children of 7)
	root->left->right->left = new Node(6);

	// level 3 (children of 15)
	root->right->left->left = new Node(12);
	root->right->left->right = new Node(18);

	// level 3 (children of 99)
	root->right->right->left = new Node(19);

	// level 4 (children of 18)
	// NO CHILDREN, WELL I DID HAVE 19 HERE BUT I KEEP GETTING THE TREEHEIGHT() WRONG SO I MOVED IT TO AS A SON OF 99

	return root;
}

// Write a function that will search the BST for a target value
//	input: integer target to search for,
			// pointer to root Node
// 	returns: true or false depending on if the value is found
// You should write this function recursively! What is the base case? What is the general case?
bool searchTree(int target, Node* root) {
	// Base case 1: 
	if (root == nullptr) {
		return false;
	}
	// Base case 2: when the target is found 
	if (root->key == target) {
		return true;
	}
	// General case (recursive) if-else statement that goes to the right or left depending of the value 
	if (target < root->key) {
		return searchTree(target, root->left);
	} else {
		return searchTree(target, root->right);
	}	
}

// Write a function that will return the total number of Nodes in the tree
// 	input: pointer to the root Node
// 	returns: number of nodes currently in the tree
// You should write this function recursively!
int treeSize(Node* root) {
	// base case: if the tree is empty or works to stop recursion
	if (root == nullptr) {
		return 0;
	}

	// General case : performs recursion, adding both right and left side + 1 for the current node
	return treeSize(root->right) + treeSize(root->left) + 1;
}


// BONUS! Write a function that will determine the height of the tree
int treeHeight(Node* root) {
    if (root == nullptr) {
        return -1; // height in terms of edges
    }
	// getting the height of both sides
    int leftSum = treeHeight(root->left); // performs recursion until finding the max height for the left side of the tree
    int rightSum = treeHeight(root->right); // performs recursion until finding the max height for the right side of the tree

    return 1 + std::max(leftSum, rightSum); // with max function, it will compare both sides and return the one with higher height value
}

