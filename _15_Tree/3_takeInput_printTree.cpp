//Here we take the input from the user for the tree and then print the tree in two ways
// Steps to take the input
// 1. First we enter our root->data
// 2. Now, we ask user for the number of children root has
// 3. Now, we iterate our number of children.
// 4. In or loop we call our function again recursively. This takes input for the child nodes and return the root of that child tree.
// 5. We push_back child to our root.
// 6. We return root.


#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode<T>*> children;
        TreeNode(T data){
            this->data = data;
        }
};
void printTree(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<endl;
    for(int i=0; i<root->children.size(); i++){
        printTree(root->children[i]);
    }
    return;
}
TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter Data : ";
    cin>>rootData;
    
    TreeNode<int>* root =new TreeNode<int>(rootData);
    
    int n;
    cout<<"Enter the num of child of "<<rootData<<" : ";
    cin>>n;
    
    for(int i=0; i<n; i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
    
}
void printTree2(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" : ";
    for(int i=0; i<root->children.size(); i++){
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;
    for(int i=0; i<root->children.size(); i++){
        printTree2(root->children[i]);
    }
}
int main() {
    // Write C++ code here
    TreeNode<int>* root = takeInput();
    
    printTree(root);
    printTree2(root);
    return 0;
}
// Code Result
// Enter Data : 1
// Enter the num of child of 1 : 2
// Enter Data : 2
// Enter the num of child of 2 : 2
// Enter Data : 4
// Enter the num of child of 4 : 0
// Enter Data : 5
// Enter the num of child of 5 : 0
// Enter Data : 3
// Enter the num of child of 3 : 1
// Enter Data : 6
// Enter the num of child of 6 : 0
// 1
// 2
// 4
// 5
// 3
// 6
// 1 : 2 3 
// 2 : 4 5 
// 4 : 
// 5 : 
// 3 : 6 
// 6 : 
