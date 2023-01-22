// Longest Palindromic Substring
// Send Feedback
// You are given a string S .You have to find the length of the longest palindromic substring of S.
// Input Format:
// First line of input contains the string S.
// Constraints:
// 1 <= |S| <= 4*10^6
// Output Format:
// You have to print the length of longest palindromic substring
// Sample Input 1:
// zkpbhxkmauuamkxsyi
// Sample Output 1:
// 10
// Explanation:
// In the given sample test case, the longest palindromic substring is: xkmauuamkx.

#include<bits/stdc++.h>
using namespace std;

int f(string s){
    int n = s.length();
    int max_len = INT_MIN;
    int curr_len;

    for(int i=0; i<n; i++){
        int l = i;
        int r = i;
        while(l>=0 && r<n && s[l]==s[r]){
            curr_len = r-l+1;
            max_len = max(max_len, curr_len); 
            l--;
            r++;
        }

        l = i;
        r = i+1;
        while(l>=0 && r<n && s[l]==s[r]){
            curr_len = r-l+1;
            max_len = max(max_len, curr_len); 
            l--;
            r++;
        }

    }
    return max_len;
}


int main(){
    
    // write your code here
    string s;
    cin>>s;
    cout<<f(s)<<endl;
    return 0;
}
