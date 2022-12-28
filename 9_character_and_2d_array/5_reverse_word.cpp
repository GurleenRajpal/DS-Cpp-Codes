// Reverse Word Wise
// Send Feedback
// Reverse the given string word wise. That is, the last word in given string should come at 1st place,
// last second word at 2nd place and so on. Individual words should remain as it is.
// Input format :
// String in a single line
// Output format :
// Word wise reversed string in a single line
// Constraints :
// 0 <= |S| <= 10^7
// where |S| represents the length of string, S.
// Sample Input 1:
// Welcome to Coding Ninjas
// Sample Output 1:
// Ninjas Coding to Welcome
// Sample Input 2:
// Always indent your code
// Sample Output 2:
// code your indent Always

#include <iostream>

using namespace std;
void reverseStringWordWise(char input[]) {
    // Write your code here
    int words = 0;
    int i = 0;
    int len = 0;
    while(input[i]!='\0'){
        if(input[i]==' '){
            words++;
        }
        len++;
        i++;
    }
    words++;
    
    i = 0;
    int j = len-1;
    
    while(i<j){
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++;
        j--;
    }
    //cout<<input<<endl;
    i = 0;
    j = 0;
    int k = 0;
    while(words>0){
        while(input[j]!=' ' && input[j]!='\0'){
            j++;
        }
        k = j-1;
        while(i<k){
            int temp = input[i];
        	input[i] = input[k];
        	input[k] = temp;
        	i++;
        	k--;
        }
        //break;
        
        j++;
        i = j;
        words--;
    }
}

#include <iostream>
using namespace std;

int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
