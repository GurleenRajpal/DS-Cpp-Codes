 Code: BST Class
Send Feedback
Implement the BST class which includes following functions -
1. insert -
Given an element, insert that element in the BST at the correct position.
If element is equal to the data of the node, insert it in the left subtree.
2. search
Given an element, find if that is present in BST or not. Return true or false.
3. delete -
Given an element, remove that element from the BST. If the element which is to be 
deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive) -
Print the BST in in the following format -
For printing a node with data N, you need to follow the exact format -

N:L:x,R:y

where, N is data of any node present in the binary tree. x and y are the values of 
left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.

/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
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
	
***********************************************************/
#include<climits>
#include<queue>
class BST {
    // Define the data members
    BinaryTreeNode<int>* root;
    
   public:
    BST() { 
        // Implement the Constructor
        root=NULL;
    }

	/*----------------- Public Functions of BST -----------------*/
	private:
    BinaryTreeNode<int>* getMin(BinaryTreeNode<int>* root){
        if(root==NULL){
            return NULL;
        }
        int min_value = root->data;
        queue<BinaryTreeNode<int>*> q;
        BinaryTreeNode<int>* front, *minNode;
        q.push(root);
        minNode = root;
        while(!q.empty()){
            front = q.front();
            q.pop();
            if(minNode->data>front->data){
                minNode = front;
            }
            if(front->right){
                q.push(front->right);
            }
            if(front->left){
                q.push(front->left);
            }
        }
        return minNode;
    }
    BinaryTreeNode<int>* remove(BinaryTreeNode<int>* root, int data){
        if(root==NULL){
            return NULL;
        }
        if(root->data>data){
            root->left = remove(root->left, data);
        }
        else if(root->data<data){
            root->right = remove(root->right, data);
        }
        else{
            if(!root->left && !root->right){
                return NULL;
            }
            else if(!root->left && root->right){
                BinaryTreeNode<int>* temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if(root->left && !root->right){
                BinaryTreeNode<int>* temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else{
                BinaryTreeNode<int>* minNode = root->right;
                while(minNode->left){
                    minNode = minNode->left;
                }
                int minValue = minNode->data;
                root->data = minNode->data;
                root->right = remove(root->right, minValue);
                return root;
            }
        }
        return root;
        
    }
    public:
    
    void remove(int data) { 
        // Implement the remove() function 
        root = remove(root, data);
    }
	private:
    void printTree(BinaryTreeNode<int>* root) {
		if (root == NULL) {
			return;
		}
		cout << root->data << ":";
		if (root->left != NULL) {
			cout << "L:" << root->left->data<<",";
		}

		if (root->right != NULL) {
			cout << "R:" << root->right->data;
		}
		cout << endl;
		printTree(root->left);
		printTree(root->right);
	}

    public:
    void print() { 
        // Implement the print() function
        printTree(root);
        
    }
	private:
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* root){
        
        if(root==NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        
        if(root->data>=data){
            root->left = insert(data, root->left);
        }
        
        else{
            root->right = insert(data, root->right);
        }
        
        return root;
        
    }
    public:
    void insert(int data) { 
        // Implement the insert() function 
        root = insert(data, root);
        return;
    }

    private:
    bool search(int data, BinaryTreeNode<int>* root){
        if(root==NULL){
            return false;
        }
        if(root->data==data){
            return true;
        }
        else if(root->data>data){
            return search(data, root->left);
        }
        else{
            return search(data, root->right);
        }
    }
    public:
    bool search(int data) {
		// Implement the search() function 
        return search(data, root);
    }
};

#include <iostream>
using namespace std;

template <typename T>
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

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}
