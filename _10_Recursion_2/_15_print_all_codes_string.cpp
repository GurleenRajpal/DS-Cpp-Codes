// Print all Codes - String
// Send Feedback
// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. 
// Write a program to print the list of all possible codes that can be generated from the given string.
// Note : The order of codes are not important. Just print them in different lines.
// Input format :
// A numeric string S
// Output Format :
// All possible codes in different lines
// Constraints :
// 1 <= Length of String S <= 10
// Sample Input:
// 1123
// Sample Output:
// aabc
// kbc
// alc
// aaw
// kw

#include <string.h>
#include <string>
using namespace std;
char itoc(int i){
    return 'a'+i-1;
}

int ctoi(char c){
    return c-'0';
}

void helper(string input, string output){
    
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    
    char s1 = itoc(ctoi(input[0]));
    
    helper(input.substr(1), output+s1);
    
    int num2 = ctoi(input[0])*10+ctoi(input[1]);
    
    if(num2>=10 && num2<=26){
        char s2 = itoc((ctoi(input[0]))*10+ctoi(input[1]));
        helper(input.substr(2), output+s2);
    }
    
    
}
void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string output = "";
    
    helper(input, output);
    
}

#include <iostream>
using namespace std;

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
