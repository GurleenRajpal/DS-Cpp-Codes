// Code : Edit Distance
// Send Feedback
// Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
// Edit Distance
// Edit Distance of two strings is minimum number of operations required to make one string equal to other. 
// In order to do so you can perform any of the following three operations only :
// 1. Delete a character
// 2. Replace a character with another one
// 3. Insert a character
// Note
// Strings don't contain spaces
// You need to find the edit distance from input string1 to input string2.
// Input Format :
// The first line of input contains a string, that denotes the value of s. The following line contains a string, that denotes the value of t.
// Output Format :
// The first and only line of output contains the edit distance value between the given strings.
// Constraints :
// 1<= m,n <= 10
// Time Limit: 1 second
// Sample Input 1 :
// abc
// dc
// Sample Output 1 :
// 2

#include <cstring>
#include <iostream>
using namespace std;

#include<climits>
int editDistance(string s1, string s2) {
    
    if(s1==s2){
        return 0;
    }
    
    
    if(s1[0]==s2[0]){
        return editDistance(s1.substr(1),s2.substr(1));
    }
    
    int way1 = INT_MAX;
    if(s1.length()>0){
    	string insertS = s1[0]+s2;
    	way1 = 1 + editDistance(s1+"", insertS+"");
    }
    
    int way2 = INT_MAX;
    if(s2.length()>0){
    	string deleteS = s2.substr(1);
    	way2 = 1 + editDistance(s1+"", deleteS+"");
    }
    
    int way3 = INT_MAX;
    if(s1.length()>0 && s2.length()>0){
        string replaceS = s2;
        replaceS[0] = s1[0];
        way3 = 1 + editDistance(s1+"", replaceS+"");
    }
    
    return min(way1, min(way2, way3));
    
}


int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}
