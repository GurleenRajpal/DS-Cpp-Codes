// Pair Star
// Send Feedback
// Given a string S, compute recursively a new string where identical chars that are 
// adjacent in the original string are separated from each other by a "*".
// Input format :
// String S
// Output format :
// Modified string
// Constraints :
// 0 <= |S| <= 1000
// where |S| represents length of string S.
// Sample Input 1 :
// hello
// Sample Output 1:
// hel*lo

// Change in the given string itself. So no need to return or print the changed string.
#include<cstring>
void pS(char input[], int i){
    
    if(strlen(input+1)==0){
        return;
    }
    bool changed = false;

    
    if(input[i]==input[i+1]){
        for(int j = strlen(input);j>i;j--){
            input[j+1] = input[j];
        }
        input[i+1] = '*';
        changed = true;
    }
    
    if(changed){
        i = i+1;
    }
    pS(input+1, i);
    
}

void pairStar(char input[]) {
    // Write your code here
	int size = strlen(input);
    
    pS(input, 0);
    
}

#include <iostream>
using namespace std;

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
