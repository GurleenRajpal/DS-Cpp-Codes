//Our tree will have a node that has data and address to all of its children.
//So, we just need address of root as it has address of all the child nodes.
//In out class we store two variables - one to store the value and the other to store the address of all the children


#include <iostream>
#include <vector>
using namespace std;

//template is used to make it general
template <typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode<T>*> children;
        TreeNode(T data){
            this->data = data;
        }
};

void printTree(TreeNode<int>* T){
    cout<<T->data<<endl;
    for(int i=0; i<T->children.size(); i++){
        printTree(T->children[i]);
    }
    return;
}

int main() {
    // Write C++ code here
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);    
    TreeNode<int>* node2 = new TreeNode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);
    
    printTree(root);
    
    return 0;
}
