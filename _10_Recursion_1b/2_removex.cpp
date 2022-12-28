// Remove X
// Send Feedback
// Given a string, compute recursively a new string where all 'x' chars have been removed.
// Input format :
// String S
// Output format :
// Modified String
// Constraints :
// 1 <= |S| <= 10^3
// where |S| represents the length of string S. 
// Sample Input 1 :
// xaxb
// Sample Output 1:
// ab

// Change in the given string itself. So no need to return or print anything
#include<cstring>
void removeX(char input[]) {
    // Write your code here
    if(input[0]=='\0'){
        return;
    }
    
    if(input[0]=='x'){
        for(int i=0;i<strlen(input);i++){
            input[i] = input[i+1];
        }
    }
    
    if(input[0]=='x'){
        removeX(input);
    }
    else{
        removeX(input+1);
    }
    
// removeX(input+1);
}
#include <iostream>
using namespace std;

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
