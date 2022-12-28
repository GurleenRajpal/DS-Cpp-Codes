// Check Palindrome (recursive)
// Send Feedback
// Check whether a given String S is a palindrome using recursion. Return true or false.
// Input Format :
// String S
// Output Format :
// 'true' or 'false'
// Constraints :
// 0 <= |S| <= 1000
// where |S| represents length of string S.
// Sample Input 1 :
// racecar
// Sample Output 1:
// true
// Sample Input 2 :
// ninja
// Sample Output 2:
// false

#include<cstring>
#include<iostream>
using namespace std;
bool helper(char input[], int i, int e){
    
     if(i>=e){
         return true;
     }
     if(input[i]!=input[e-1]){
         return false;
     }
    
    bool k = helper(input, i+1, e-1);
    
    return k;
}

bool checkPalindrome(char input[]) {
    // Write your code here
	if(strlen(input)==0 || strlen(input)==1){
        return true;
    }
    
    int size = strlen(input);
    
    return helper(input, 0, size);
    
}

#include <iostream>
using namespace std;

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}



