//  Code Breaker
// Send Feedback
// Jack Ryan is one of the world’s most famous cryptographers. He has been recently tasked with breaking 
// a code with which our country’s enemies are communicating. He has thought of a possible break in the code, 
// using a very complex system of strings, which thankfully, you have nothing to do with. You are tasked with
// a little problem. Jack will give you n strings, labelled S1, S2, …. Sn, along with q queries.
// In each query, you have an integer X and a string CODE. You will take into consideration strings S1 to SX. 
// Among these selected strings, consider all the strings such that their longest common prefix with CODE is 
// the maximum possible. Now, from these strings, print the lexicographically smallest one. This would give 
// Jack tremendous insight into further breaking the code. Can you help him?
// Input Format:

// The first line of the input contains a single integer N.
// N lines follow. For each valid i, the i-th of these lines contains Chef's string Si.
// The next line contains a single integer Q.
// The following Q lines describe queries. Each of these lines contains an interger R, followed by a space and a string P

// Constraints:

// 1 ≤ n ≤ 100,000 
// 1 ≤ |Si| ≤ 10 for each valid i
// 1 ≤ q ≤ 100,000
// 1 ≤ X ≤ n
// 1 ≤ |CODE| ≤ 10

// Output Format:

// For each query, print a single line containing the string that satisfies the required conditions — the answer to that query.

// Sample Input 1:

// 4
// abcd
// abce
// abcdex
// abcde
// 3
// 3 abcy
// 3 abcde
// 4 abcde

// Sample Output 1:

// abcd
// abcdex
// abcde

#include<bits/stdc++.h>
using namespace std;
class TrieNode {                      
public:
    TrieNode * children[26];
    bool isTerminal;
    int index;
    TrieNode()
    {
        isTerminal=false;
        index = INT_MAX;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }

};

void insert(TrieNode* root, string s, int n){
    if(s.length()==0){
        root->isTerminal = true;
        root->index = min(root->index, n);
        return;
    }
    TrieNode* child;
    int i = s[0]-'a';
    if(root->children[i]==NULL){
        child = new TrieNode();
        root->children[i] = child;
    }
    else{
        child = root->children[i];
    }
    child->index = min(child->index, n);
    insert(child, s.substr(1), n);
}

void print(TrieNode *root, string s, vector<string>& ans, int k) {
  TrieNode *temp = root;
  if (root->isTerminal && root->index<=k) {
    
    // cout << s << endl;
    ans.push_back(s);
    return;
  }
    if(root==NULL){
        return;
    }
  // got to last node
  for (int i = 0; i < 26; i++) {
    temp = root;
    if (temp->children[i] != NULL && temp->children[i]->index<=k) {
      char suffix = (int)i + (int)'a';
      print(temp->children[i], s + suffix, ans, k);
    //   if(temp->children[i]->index<=k){
    //       ans.push_back(s+suffix);
    //   }
    }
  }
  return;
}
string getPrefix(TrieNode* root, string s, int k){
    TrieNode *child;
    TrieNode *temp = root;
    string smallAns = "";
    // cout<<"here"<<endl;
    int i = 0;
    for (; i < s.length(); i++) {
        int ind = s[i] - 'a';
        if(temp->children[ind]==NULL){
            break;
        }
        child = temp->children[ind];
        if(child->index>k){
            break;
        }
        temp = child;
    }
    smallAns = s.substr(0, i);
    // cout<<"Small Ans "<<smallAns<<endl;
    return smallAns;
}
bool compare(string& s1, string& s2){
    return s1.size()<s2.size();
}
class query{
    public:
        int index;
        string s;
        int till;
};

bool cmp(query q1, query q2){
    return q1.till<q2.till;
}

int main(){
    
    // write your code here
    int n;
    cin>>n;
    int i = 0;
    string* arr = new string[n];
    
    TrieNode* root = new TrieNode();
    while(i<n){
        cin>>arr[i];
        i++;
        // insert(root, s, i);
    }
    // cout<<root->children[0]->index<<endl;
    int q;
    cin>>q;
    query* qs = new query[q];
    string* ansarr = new string[q];
    i = 0;
    while(i<q){
        int k;
        string s;
        cin>>k>>s;
        qs[i].index = i;
        qs[i].s = s;
        qs[i].till = k-1;
        i++;
    }
    
    sort(qs, qs+q, cmp);
    // cout<<qs[0].till<<endl;
    int minIndex = 0;
    int j = 0;
    int k = 0;
    int lastIndex = 0;
    for( ;j<q;  ){
        minIndex = qs[j].till;
        // cout<<minIndex<<endl;
        for(; lastIndex<=minIndex; lastIndex++){
            // cout<<lastIndex<<" here"<<endl;
            // cout<<arr[lastIndex]<<endl;
            insert(root, arr[lastIndex], lastIndex);
            // cout<<"here2"<<endl;
        }
        // cout<<"lastIndex "<<lastIndex<<endl;
        // cout<<"minIndex "<<minIndex<<endl;
        while(qs[j].till<=minIndex && j<q){
            // cout<<"j "<< j<<endl;
            string prefix = getPrefix(root, qs[j].s,qs[j].till);
            TrieNode* temp = root;
            TrieNode* child;
            for(int m=0; m<prefix.length(); m++){
                int ind = prefix[m] - 'a';
                child = temp->children[ind];
                temp = child;
            }

            vector<string> ans;
            print(temp, prefix, ans, qs[j].till);
            // sort(ans.begin(), ans.end(), compare);
            ansarr[qs[j].index] = ans[0];
            j++;
        }
    }

   
    // string prefix = getPrefix(root, s, k);
    // TrieNode* temp = root;
    // TrieNode* child;
    // for(int i=0; i<prefix.length(); i++){
    //     int ind = prefix[i] - 'a';
    //     child = temp->children[ind];
    //     temp = child;
    // }
    // vector<string> ans;
    // print(temp, prefix, ans, k);
    // sort(ans.begin(), ans.end(), compare);
    // for(int i=0; i<ans.size(); i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;

    for(int i=0; i<q; i++){
        cout<<ansarr[i]<<endl;
    }
    return 0;
}
