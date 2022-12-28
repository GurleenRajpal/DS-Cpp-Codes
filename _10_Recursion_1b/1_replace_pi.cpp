// Replace pi (recursive)
// Send Feedback
// Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
// Constraints :
// 1 <= |S| <= 50
// where |S| represents the length of string S. 
// Sample Input 1 :
// xpix
// Sample Output :
// x3.14x
// Sample Input 2 :
// pipi
// Sample Output :
// 3.143.14

// Change in the given string itself. So no need to return or print anything
#include<cstring>
void rp(char input[], int i){
    if(input[i]=='\0'|| input[i+1]=='\0'){
        return;
    }
    
    if(input[i]=='p' && input[i+1]=='i'){
        
        for(int j=strlen(input);j>=i+2;j--){
            input[j+2] = input[j];
        }
        
        input[i] = '3';
        input[i+1] = '.';
        input[i+2] = '1';
        input[i+3] = '4';
    }
    rp(input, i+1);
}

void replacePi(char input[]) {
	// Write your code here
    
	//int size = strlen(input);
    
    rp(input, 0);
}


#include <iostream>
using namespace std;

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
