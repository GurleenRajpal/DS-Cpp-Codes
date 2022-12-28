// Reverse Each Word
// Send Feedback
// Aadil has been provided with a sentence in the form of a string as a function parameter. 
//   The task is to implement a function so as to print the sentence such that each word in the sentence is reversed.
// Example:
// Input Sentence: "Hello, I am Aadil!"
// The expected output will print, ",olleH I ma !lidaA".
// Input Format:
// The first and only line of input contains a string without any leading and trailing spaces. The input string represents the sentence given to Aadil.
// Output Format:
// The only line of output prints the sentence(string) such that each word in the sentence is reversed. 
// Constraints:
// 0 <= N <= 10^6
// Where N is the length of the input string.

// Time Limit: 1 second
// Sample Input 1:
// Welcome to Coding Ninjas
// Sample Output 1:
// emocleW ot gnidoC sajniN

void reverseEachWord(char input[]) {

    // Write your code here
    int i = 0;
    int k = i;
    int j = i;

    while(input[i]!='\0'){
        

        while(input[j]!=' ' && input[j]!='\0'){
            j++;
        }
		
        i = j;
		    j = j-1;
        while(k<j){
            int temp = input[k];
            input[k] = input[j];
            input[j] = temp;
            j--;
            k++;
        }
        
        j = i+1;
        k = i+1;

    }

}


#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}
