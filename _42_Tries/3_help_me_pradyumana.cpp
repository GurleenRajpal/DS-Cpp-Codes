//  Help Me Pradyumana!
// Send Feedback
// Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his 
// auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his
// own app for mobile which will restrict auto - correct feature, instead it will provide auto - 
// completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's
// App will show options such as fact, factorial, factory. Now, he can chose from any of these 
// options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said 
// "You will be given set of words(words may repeat too but counted as one only). Now, as user starts 
// the app, he will make queries(in lowercase letters only). So, you have to print all the words of 
// dictionary which have the prefix same as given by user as input. And if no such words are available, 
// add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P So, 
// implement a program for him such that he can release it on Fun Store.
// Input Format:

// Single integer N which denotes the size of words which are input as dictionary
// N lines of input, where each line is a string of consisting lowercase letter
// Single integer Q which denotes the number of queries.
// Q number of lines describing the query string on each line given by user

// Constraints:

// 1 ≤ N ≤ 30000
// sum(len(string[i])) ≤ 2∗10^5
// 1 ≤ Q ≤ 10^3

// Output Format:

// If auto - completions exists, output all of them in lexicographical order else output "No suggestions" without quotes

// Sample Input 1:

// 3
// fact
// factorial
// factory
// 2
// fact
// pradyumn

// Sample Output 1:

// fact
// factorial
// factory
// No suggestions

#include<iostream>
using namespace std;
class trieNode{
    public:
        trieNode** children;
        bool isTerminal;
        trieNode(){
            children = new trieNode*[26];
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

void insert(trieNode* root, string s){
    if(s.length()==0){
        root->isTerminal = true;
        return;
    }
    int index = s[0] - 'a';
    trieNode* child;
    if(root->children[index]==NULL){
        child = new trieNode();
        root->children[index] = child;
    }
    else{
        child = root->children[index];
    }
    insert(child, s.substr(1));
    return;
}

bool search(trieNode* root, string s){
    if(s.length()==0){
        return true;
    }
    int index = s[0] - 'a';
    if(root->children[index]==NULL){
        return false;
    }
    return search(root->children[index], s.substr(1));
}

void print(trieNode* root, string s){
    trieNode* temp = root;
    if(root->isTerminal){
        cout<<s<<endl;
        // return;
    }
    //got to last node
    for(int i=0; i<26; i++){
        temp = root;
        if(temp->children[i]!=NULL){
            char suffix = (int) i +(int) 'a';
            print(temp->children[i], s + suffix); 
        }
    }
    return;
}


int main(){
    int n, q;
    string s;
    cin>>n;
    trieNode* root = new trieNode();

    while(n--){
        cin>>s;
        insert(root, s);
    }
    cin>>q;
    while(q--){
        cin>>s;
        if(search(root, s)){
            //go till that node
            trieNode* child;
            trieNode* temp = root;
            for(int i=0; i<s.length(); i++){
                int index = s[i] - 'a';
                child = temp->children[index];
                temp = child;
            }
            print(temp, s);
        }
        else{
            cout<<"No suggestions"<<endl;
            insert(root, s);
        }
    }
    return 0;
}
