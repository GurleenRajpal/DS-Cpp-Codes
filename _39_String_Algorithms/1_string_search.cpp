// String Search
// Send Feedback
// You are given an string S and a test string T. You have to find whether string S is a substring of the string T.
// Input Format:
// First line of input will contain an integer T, representing the number of test cases
// Each test case is as follows:
// Line 1: contains the string S.
// Line 2: contains the string T.
// Constraints:
// 1 <= T <= 100
// 1 <= |S|, |T| <= 10^5
// Output Format:
// For each test case print "Yes" if S is present in T or "No" otherwise.
// Sample Input 1:
// 2
// ye
// wnpnzijdi
// ao
// jaoalc
// Sample Output 1:
// No
// Yes

#include<bits/stdc++.h>
using namespace std;

int lps[100005];


void getLPS(string pattern,int n){
    lps[0] = 0;
    int i = 1, j = 0;

    while(i<n){
        if(pattern[i]==pattern[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool search(string text, string pattern){
    int lenText = text.length();
    int lenPat = pattern.length();
    
    // cout<<pattern<<" "<<text<<endl;
    getLPS(pattern, pattern.length());

    int i = 0,  j=0;
    while(i<lenText && j<lenPat){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    

    if(j==lenPat) return true;
    return false;
}

int main(){
    
    // write your code here
    
    int t;
    cin>>t;
    while(t--){
        for (int i = 0; i < 100005; i++) {
            lps[i] = 0;
        }
        string text, pattern;
        cin>>pattern>>text;
        

        if(search(text, pattern)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        
    }
    return 0;
}
