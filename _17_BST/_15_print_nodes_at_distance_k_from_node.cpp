//  Print nodes at distance k from node
// Send Feedback
// You are given a Binary Tree of type integer, a target node, and an integer value K.
// Print the data of all nodes that have a distance K from the target node. 
// The order in which they would be printed will not matter.
// Input Format:

// The first line of input will contain the node data, all separated by a single space. 
// Since -1 is used as an indication whether the left or right node data exist for root, 
// it will not be a part of the node data.

// The second line of input contains two integers separated by a single space, 
// representing the value of the target node and K, respectively.

// Output Format:

// All the node data at distance K from the target node will be printed on a new line.

// The order in which the data is printed doesn't matter.

// Constraints:

// 1 <= N <= 10^5
// Where N is the total number of nodes in the binary tree.

// Time Limit: 1 sec

// Sample Input 1:

// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 3 1

// Sample Output 1:

// 9
// 6

// Sample Input 2:

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
// 3 3

// Sample Output 2:

// 4
// 5


void printAtDepthK(BinaryTreeNode<int> *targetNode, int k) {
  if (targetNode == NULL || k < 0) {
    return;
  }
  if (k == 0) {
    cout << targetNode->data << endl;
    return;
  }
  printAtDepthK(targetNode->left, k - 1);
  printAtDepthK(targetNode->right, k - 1);
}
int helper(BinaryTreeNode<int> *root, int node, int k) {

  if (root == NULL) {
    return -1;
  }

  if (root->data == node) {
    printAtDepthK(root, k);
    return 0;
  }

  int dl = helper(root->left, node, k);
  if (dl != -1) {
    if ((dl + 1) == k) {
      cout << root->data << endl;
    } else {
      printAtDepthK(root->right, k - dl - 2);
    }
    return 1 + dl;
  }

  int dr = helper(root->right, node, k);
  if (dr != -1) {
    if ((dr + 1) == k) {
      cout << root->data << endl;
    } else {
      printAtDepthK(root->left, k - dr - 2);
    }
    return 1 + dr;
  }

  return -1;
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
  int kp = helper(root, node, k);
}
