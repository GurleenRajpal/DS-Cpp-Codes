//  Ninja and Multiset
// Send Feedback
// Our problem setter, Ninja, is fascinated by different types of sets. Quite recently, he 
// came across a new term- Multiset. Multiset is a set, where equal elements are allowed. He 
// started experimenting with it and has managed to frame a pretty interesting problem for you to solve.
// You are given a multiset G, initially containing only 0, and a few queries q. Queries are actually of 3 types:

// "+ x" — This query adds an integer x to the given multiset.
// "- x" — This query erases one occurrence of x from the given multiset. Before this query is encountered, 
// it is guaranteed that the multiset will contain integer x at least once.
// "? x" — In this query, you are given integer x and you need to compute the maximum value of bitwise 
// exclusive OR (also known as XOR) of integer x and some integer y from the given multiset.

// Input Format:

// First line on input contain Q (number of queries ).
// Next Q line contain Q queries as defined above.

// Output Format:

// For each query of type '?' print the answer in new line

// Constraints:

// 1 <= Q <= 10^5
// 1 <= x <= 10^9

// Sample Input 1:

// 8
// ? 8
// ? 5
// + 10
// ? 5
// ? 4
// + 4
// - 4
// ? 10

// Sample Output 1:

// 8
// 5
// 15
// 14
// 10

// Explanation:

// Initially the multiset contains only the integer 0. So for the first query, answer is 8 XOR 0 = 8.
// Similarily, the answer for second query is 5 XOR 0 = 5.
// After the third query, 10 is added to the multiset.
// For the fourth query, 5 will be XOR'ed with 0 and 10. Out of these, 5 XOR 10 = 15 is max.
// Similarily, for the fifth query, 4 will be XOR'ed with 0 and 10. Out of these, 4 XOR 10 = 14 is max.
// After the sixth query, 4 is added to the multiset.
// After the seventh query, 4 is erased from the multiset.
// For the last query, 10 is XOR'ed with 0 and 10. Out of these, 10 XOR 0 = 10 is max.

#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
        trieNode* left;
        trieNode* right;
        int count = 0;
        trieNode(){
            left = NULL;
            right = NULL;
        }
};

void remove(trieNode* root, int n){
    trieNode* curr = root;
    for(int i=0; i<=31; i++){
        int bit = (n>>i)&1;

    }
}
void insert(trieNode* root, int n, int val){
    trieNode* curr = root;
    // root->count+=val;
    curr->count+=val;
    for(int i=31; i>=0; i--){
        int bit = (n>>i)&1;
        if(bit==0){
            if(curr->left==NULL){
                curr->left = new trieNode();
            }
            curr = curr->left;
            curr->count+=val;
        }
        else{
            if(curr->right==NULL){
                curr->right = new trieNode();
            }
            curr = curr->right;
            curr->count+=val;
        }
    }
    // curr->count+=val;
   
}

int query(trieNode* root, int n){
    int sum = 0;
    trieNode* temp = root;
    for(int i=31; i>=0; i--){
        int b = (n>>i)&1;
        if(temp->count>0){
            if (b == 0) {
                if (temp->right) {
                    temp = temp->right;
                    sum += pow(2,i);
                } else {
                    temp = temp->left;
                }
            }
            else {
                if (temp->left) {
                    temp = temp->left;
                    sum += pow(2, i);
                } else {
                    temp = temp->right;
                }
            }
        }
        else{
            return n;
        }
    }

    return sum;
}

int main(){
    
    // write your code here
    multiset<int> ms;
    ms.insert(0);
    trieNode* root = new trieNode();
    insert(root, 0, 1);

    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        char c;
        int n;
        cin>>c>>n;
       if(c=='+'){
            ms.insert(n);
            insert(root, n, 1);
        }
        else if(c=='-'){
            ms.erase(ms.find(n));
            insert(root, n, -1);
        }
        else if(c=='?'){
            //max value of bitwise xor
            // int val = INT_MIN;
            // multiset<int>::iterator it;
            // for(it=ms.begin(); it!=ms.end(); it++){
            //     val = max(val,(*it)^n);
            // }
            // cout<<val<<endl;
            cout<<query(root, n)<<endl;
        }
    }

    return 0;
}
