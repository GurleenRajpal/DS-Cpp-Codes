// Code : Edit Distance (Memoization and DP)
// Send Feedback
// You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
// Edit Distance of two strings is the minimum number of steps required to make one 
// string equal to the other. In order to do so, you can perform the following three operations:
// 1. Delete a character
// 2. Replace a character with another one
// 3. Insert a character
// Note :
// Strings don't contain spaces in between.
//  Input format :
// The first line of input contains the string S of length M.

// The second line of the input contains the String T of length N.
// Output format :
// Print the minimum 'Edit Distance' between the strings.
// Constraints :
// 0 <= M <= 10 ^ 3
// 0 <= N <= 10 ^ 3

// Time Limit: 1 sec
// Sample Input 1 :
// abc
// dc
// Sample Output 1 :
// 2
//  Explanation to the Sample Input 1 :
//  In 2 operations we can make string T to look like string S.
// First, insert character 'a' to string T, which makes it "adc".

// And secondly, replace the character 'd' of string T with 'b' from the string S. This would make string T as "abc" which is also string S. 

// Hence, the minimum distance.
// Sample Input 2 :
// whgtdwhgtdg
// aswcfg
// Sample Output 2 :
// 9

#include<climits>
#include<vector>
int helper(string s1, string s2, vector<vector<int> >& dp ) {
    
    int m = s1.length();
    int n = s2.length();
    
    if(s1==s2){
        return 0;
    }
    
    
    if(dp[m][n]!=-1) return dp[m][n]; 
    
    if(s1[0]==s2[0]){
        return dp[m][n] = helper(s1.substr(1),s2.substr(1),dp);
    }
    
    
    
    int way1 = INT_MAX;
    if(s1.length()>0){
    	string insertS = s1[0]+s2;
    	way1 = 1 + helper(s1, insertS,dp);
    }
    
    int way2 = INT_MAX;
    if(s2.length()>0){
    	string deleteS = s2.substr(1);
    	way2 = 1 + helper(s1, deleteS, dp);
    }
    
    int way3 = INT_MAX;
    if(s1.length()>0 && s2.length()>0){
        string replaceS = s2;
        replaceS[0] = s1[0];
        way3 = 1 + helper(s1, replaceS, dp);
    }
    
    return dp[m][n] = min(way1, min(way2, way3));
    
}

int editDistance(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    vector<vector<int> > dp(m+1 , vector<int>(m+n+1, -1));
    
    return helper(s1, s2, dp);
    
}
