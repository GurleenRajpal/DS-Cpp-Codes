// Print Keypad Combinations Code
// Send Feedback
// Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
// Note : The order of strings are not important. Just print different strings in new lines.
// Input Format :
// Integer n
// Output Format :
// All possible strings in different lines
// Constraints :
// 1 <= n <= 10^6
// Sample Input:
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

#include <iostream>
#include <string>
#include <iostream>
#include <string>
using namespace std;

void helper(int num, string options[], string output){
    if(num<=1){
        cout<<output<<endl;
        return;
    }
    int rem = num%10;
    int k = num/10;
    
    string s = options[rem];
    
    for(int i=0;i<s.length(); i++){
        helper(k, options, s[i]+output);
    }
    
}


void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output = "";
    string options[] = {"","", "abc", "def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    helper(num, options, output);
    
    
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
