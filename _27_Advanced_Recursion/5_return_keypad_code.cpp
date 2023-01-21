// Return Keypad Code
// Send Feedback
// Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
// The numbers and their corresponding codes are given below:
// 0: ""
// 1: ""
// 2: "abc"
// 3: "def"
// 4: "ghi"
// 5: "jkl"
// 6: "mno"
// 7: "pqrs"
// 8: "tuv"
// 9: "wxyz"
// Return empty string for numbers 0 and 1.
// Note:
// 1. The order of strings are not important.
// 2. The input number will have digits between: [2, 9].
// Input Format :
// First line of input will contain T number of test cases.
// Each input consists of a single line containing an integer n.
// Output Format :
// For each test case, print all possible strings in different lines.
// Constraints :
// 1 <= T <= 100
// 1 <= n <= 10^6
// Sample Input:
// 1
// 23
// Sample Output:
// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf

#include<bits/stdc++.h>
using namespace std;

string data(int n){
    string arr[] = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    return arr[n];
}

int printString(int n, string output[]){
    if(n==0 || n==1){
        output[0] = "";
        return 1;
    }    
    
    int x = n%10;
    
    int y = n/10;
    
    int k = printString(y, output);
    
    // attach array of data(x)
    string s = data(x);
    
    string temp[k];
    for(int i=0; i<k; i++){
        temp[i] = output[i];
    }
    
    int len = 0;
    //int val = 0;
    for(int i=0; i<k; i++){//gave ["d","e","f"]
        
        for(int j=0; j<s.length(); j++){//string "abc"
            
            output[len] = temp[i]+s[j] ;
            len++;
                
        }
        
    }
    
    //delete [] temp;

    return len;
    
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    string output[10000];
    while(t--){
        int n;
        cin>>n;
        if(n==0 || n==1){
            cout<<""<<endl;
        }
        else{
            int k = printString(n, output);

            for(int i=0; i<k; i++){
                cout<<output[i]<<endl;
            }
        }
    }
    
    return 0;
}
