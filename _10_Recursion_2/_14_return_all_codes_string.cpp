// Return all codes - String
// Send Feedback
// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. 
// Write a program to return the list of all possible codes that can be generated from the given string.
// Note : The order of codes are not important. And input string does not contain 0s.
// Input format :
// A numeric string
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
#include<iostream>
using namespace std;
char itoc(int i){
    return 'a'+i-1;
}

int ctoi(char c){
    return c-'0';
}
int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input.size()==0){
        return 1;
    }
    if(input.size()==1){
        output[0] = output[0]+itoc(ctoi(input[0]));
        return 1;
    }
    
    string result1[10000];
    string result2[10000];
    
    //int num1 = ctoi(input[0]);
    int l1 = getCodes(input.substr(1), result1);
    
    int num2 = ctoi(input[0])*10+ctoi(input[1]);
    int l2 = 0;
    if(num2>=10 && num2<=26){
    	l2 = getCodes(input.substr(2), result2);
    }
    
    
    int row = 0;
    for(int i=0;i<l1;i++){
        output[row] =itoc(ctoi(input[0]))+result1[i];
        row++;
    }
    for(int i=0;i<l2;i++){
        output[row] = itoc((ctoi(input[0]))*10+ctoi(input[1]))+result2[i];
        row++;
    }
    return row;
}



int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}

