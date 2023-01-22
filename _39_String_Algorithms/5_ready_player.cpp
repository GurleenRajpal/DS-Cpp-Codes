// Ready Player S?
// Send Feedback
// OASIS is a virtual reality created by the legendary James Halliday. After Halliday's death, 
// a pre-recorded message left by him announced a game, which would grant the ownership and control of the 
// OASIS to the first player who finds the Golden Easter Egg within it.
// Shivali, an OASIS player, is obsessed with the game and finding the Easter Egg. But she has to fight the 
// IOI clan, who wants to control OASIS for evil purposes. Both of them gather troops of different types and form a big army to fight each other.
// IOI has N troops of lowercase letters forming a huge army. Shivali has an army of length M.
// She will win, if the first k troops she takes from her army, can kill any of the k consecutive troops of the IOI army.
// Remember a troop of type 'a' can only kill a troop of type 'a'.
// You have to find how many times she can win.
// Input Format:
// The first line of input contains N, M and k, space separated.
// Next two lines contains the string of troops of length N and M respectively in lowercase letters.
// Constraints:
// 1 <= N, M <= 10^6
// 1 <= K <= M
// Output Format:
// Output the number of wins she is going to take at the end of the day. Print -1 if she can't win.
// Sample Input 1:
// 3 2 1
// bbb
// bb
// Sample Output 1:
// 3

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
    int n, m, k;
    cin>>n>>m>>k;
    string text, pattern;
    cin>>text>>pattern;

    string sub = pattern.substr(0, k);

    string concat = sub+"A"+text;
    // cout<<concat<<endl;

    int l = concat.length();
 
    // Construct Z array
    int Z[l];
    getZarr(concat, Z);
    // for(int i=0; i<l; i++){
    //     cout<<Z[i];
    // }
    // cout<<endl;
    int count = 0;
    // now looping through Z array for matching condition
    for (int i = k+1; i < l; i++)
    {
        // if Z[i] (matched region) is equal to pattern
        // length we got the pattern
        if (Z[i] == k) count++;
            
    }
    if(count==0)count = -1;
    cout<<count<<endl;



    return 0;
}
