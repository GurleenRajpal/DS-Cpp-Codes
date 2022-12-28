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
using namespace std;

void printK(int num, string output){
    if(num==0){
        cout<<output<<endl;
        return;
    }
    // else{
    //     string k = getString(num);
    //     for(int i=0;i<k.length();i++){
    //         output+=k[i];
    //     }
    //     return;
    // }
    int rem = num%10;
    
    int smallNo = num/10;
    string s[] = {"", "", "abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    //printK(smallNo, output);
    string k = s[rem];
    for(int i=0;i<k.length();i++){
    	printK(smallNo, k[i]+output);
    }
}


void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output="";
    printK(num, output);
    
}

#include <iostream>
#include <string>
using namespace std;

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
