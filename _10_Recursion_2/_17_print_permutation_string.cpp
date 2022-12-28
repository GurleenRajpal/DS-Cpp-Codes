// Print Permutations
// Send Feedback
// Given an input string (STR), print all possible permutations of the input string.
// Note:
// The input string may contain the same characters, so there will also be the same permutations.
// The order of permutations doesn’t matter.
// Input Format:
// The only input line contains a string (STR) of alphabets in lower case
// Output Format:
// Print each permutations in a new line
// Constraint:
// 1<=length of STR<=8
// Time Limit: 1sec
// Sample Input 1:
// cba
// Sample Output 1:
// abc
// acb
// bac
// bca
// cab
// cba

#include<iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

void printPerm(string input, string output){
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    
    // for(int i=0;i<input.length();i++){
    //     string str1 = input[i]+"";
    //     string str2 = input.substr(0, i)+
    // }
    
    for(int i=0;i<input.length();i++){
        char str1 = input[i];
        
        int length = input.length();
        
        string str2 = input.substr(0, i) + input.substr(i+1, length-i-1);
        
        printPerm(str2 , output+str1);
        
    }
    
    
    //printPerm(input.substr(1), substr+output);
    // string input2 = input.substr(1);
    // reverse(input2.begin(), input2.end());
    
    // printPerm(input2, substr+output);
    
    
}

void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    string output = "";
    printPerm(input, output);
}

int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
