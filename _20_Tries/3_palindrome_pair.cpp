// Palindrome Pair
// Send Feedback
// Given 'n' number of words, you need to find if there exist any two words which can be joined to make a 
// palindrome or any word, which itself is a palindrome.
// The function should return either true or false. You don't have to print anything.
// Input Format :

// The first line of the test case contains an integer value denoting 'n'.

// The following contains 'n' number of words each separated by a single space.

// Output Format :

// The first and only line of output contains true if the conditions described in the task are met and false otherwise.

// Constraints:

// 0 <= n <= 10^5
// Time Limit: 1 sec

// Sample Input 1 :

// 4
// abc def ghi cba

// Sample Output 1 :

// true

// Explanation of Sample Input 1:

// "abc" and "cba" forms a palindrome

// Sample Input 2 :

// 2
// abc def

// Sample Output 2 :

// false

// Explanation of Sample Input 2:

// Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'


#include <bits/stdc++.h>
using namespace std;
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */
    private:
    bool check(string word){
        // cout<<"Palin Check "<<endl;
        // cout<<word<<endl;
        for(int i=0, j=word.length()-1;i<=j;i++, j--){
            // cout<<i <<" "<<j<<endl;
            if(word[i]!=word[j]){
            	// cout<<i<<" "<<j<<endl;
                return false;
            }
        }
        // cout<<"Returned true"<<endl;
        return true;
    }
     int getindex(TrieNode *root){
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL){
                return i;
            }
        }
        return -1;
    }
    bool checkPalin(TrieNode* root, string str){
        if(root->childCount == 0){
            return check(str);
        }
        int childindex=getindex(root);
        TrieNode* child=root->children[childindex];
        char s = childindex+'a';
        str=str+s;
        return checkPalin(child,str);
    }
    bool search(TrieNode* root, string word){
        if(root==NULL){
            return false;
        }
        if(word.size()==0){
            if(root->isTerminal){
                return true;
            }
            else{
                return checkPalin(root, "");
            }
            
        }
        if(word.size()!=0 && root->isTerminal){
            return check(word);
        }
        if(root->childCount == 0){
            // cout<<word<<endl;
            return false;
        }
        
        
        
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return search(child, word.substr(1));
    }
    
    public:
    bool search(string words){
        //reverse the words
        string reversed = "";
        for(int i=words.length()-1;i>=0;i--){
            reversed+=words[i];
        }
        //searching reversed
        // cout<<reversed<<endl;
        return search(root, reversed);
    }

    bool isPalindromePair(vector<string> words) {
        // Write your code here
        
        for(int i=0;i<words.size();i++){
            add(words[i]);
        }
        for(int i=0;i<words.size();i++){
            // cout<<"Here"<<words[i]<<endl;
            if(search(words[i])){
                
                return true;
            }
        }
        return false;
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}
