// String to Integer
// Send Feedback
// Write a recursive function to convert a given string into the number it represents. 
// That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
// Input format :
// Numeric string S (string, Eg. "1234")
// Output format :
// Corresponding integer N (int, Eg. 1234)
// Constraints :
// 0 < |S| <= 9
// where |S| represents length of string S.
// Sample Input 1 :
// 00001231
// Sample Output 1 :
// 1231

#include<cstring>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int stn2(char input[], int size){
    if(size==0){
        return 0;
    }
    
    int k = input[0] - 48;
    
    int sum = k * pow(10, size-1) + stn2(input+1, size-1);
    
    return sum;
    
    
}


int stringToNumber(char input[]) {
    // Write your code here
    int size = strlen(input);
    return stn2(input, size);    
}

#include <iostream>
using namespace std;

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}

