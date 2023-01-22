// Palindromic Substrings
// Send Feedback
// Given a string S, count and return the number of substrings of S that are a palindrome.
// Single length substrings are also palindromes. You just need to print the count of palindromic substrings, not the actual substrings.
// Input Format:
// First line of input contains an integer T, representing the number of test cases.
// Next T lines contain the string S
// Constraints :
// 1 <= Length of S <= 2000
// Output Format :
// For each test case, print the count of palindrome substrings in a new line.
// Sample Input 1:
// 1
// aba
// Sample Output 1:
// 4
// Explanation:
// The 4 palindrome substrings are "a", "b", "a" and "aba".

#include<bits/stdc++.h>
using namespace std;

int f(string s){
    int n = s.length();
    int count = 0;

    for(int i=0; i<n; i++){
        int l = i;
        
        int r = i;
        while(l>=0 && r<n && s[l]==s[r]){
            l--;
            r++;
            count++;
        }
        l = i;
        r = i+1;
        while(l>=0 && r<n && s[l]==s[r]){
            l--;
            r++;
            count++;
        }
        

    }
    return count;

}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<f(s)<<endl;
    }
    return 0;
}
