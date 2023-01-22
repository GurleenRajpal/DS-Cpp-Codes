// Red Riding Hood's Adventure
// Send Feedback
// Little Red Riding Hood has to go to her grandmother’s house. Her grandmother is very sick. To 
// reach her house, Red Riding Hood has to cross a very long dark forest. She is also carrying a 
// basket full of food for her journey. The forest was much longer than anticipated, and Riding Hood 
// decided to take rest. She finds a cave and lights a campfire inside it to keep herself warm for the 
// night. But alas! The campfire attracts the Big Bad Wolf.
// Luckily the Big Bad Wolf has recently turned vegetarian, and will not eat Red Riding Hood. He 
// takes all the food that she was carrying instead, but decided to keep her as a minion. She cries 
// a lot and begs the wolf to let her go. Big Bad Wolf used to be a problem solver in the past, and 
// decides to let her go if and only if she is able to solve a problem for him. He gives the Red R
// iding Hood a long sentence “X” and a small word “W” . She has to find how many times word “W” occurs 
// as a substring of “X” (spaces in the sentence are not to be considered). Red Riding Hood is just a kid, 
// you have to help her solve the problem and escape the Big Bad Wolf.
// Input Format :
// First line of input will contain T(number of test cases). Each test case follows.
// Line 1: contains the sentence X
// Line 2: contains the string W
// Constraints:
// 1 <= T <= 100
// 1 <= |S| ,|s| <= 10^5 
// Output Format:
// For each test case print the answer in a new line.
// Sample Input 1:
// 4
// axb ycz d
// abc
// ab  cab cabc abc
// abc
// aab acbaa bbaaz
// aab
// aaaaaa
// aa
// Sample Output 1:
// 0
// 4
// 2
// 5

#include<bits/stdc++.h>
using namespace std;

void getZarr(string concat, int Z[]){
    int n = concat.length();
    int l=0, r=0, k;
    Z[0] = 0;

    for(int i=1; i<n; i++){
        if(i>r){
            l = r = i;
            while(r<n && concat[r-l]==concat[r]){
                r++;
            }
            Z[i] = r-l;
            r--;
            
        }
        else{
            k = i-l;
            if(Z[k]<r-i+1){
                Z[i] = Z[k];
            }
            else{
                l = i;
                while (r < n && concat[r - l] == concat[r]) {
                  r++;
                }
                Z[i] = r - l;
                r--;
            }
        }
    }
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        string text, pattern;
        cin.ignore();
        getline(cin, text, '\n');
        cin>>pattern;
        int k = pattern.length();
        string concat = pattern+"$";
        for(int i=0; i<text.length(); i++){
            if(text[i]==' ')continue;
            concat+=text[i];
        }
        // cout<<concat<<endl;

        int l = concat.length();
        int Z[l];

        getZarr(concat,Z);
        int count = 0;
        for(int i=k; i<l; i++){
            if(Z[i]==k) count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
