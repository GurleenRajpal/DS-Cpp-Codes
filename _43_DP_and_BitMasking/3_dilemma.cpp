//  Dilemma
// Send Feedback
// Abhishek, a blind man recently bought N binary strings all of equal length .A binary string 
// only contains '0's and '1's . The strings are numbered from 1 to N and all are distinct, 
// but Abhishek can only differentiate between these strings by touching them. In one touch 
// Abhishek can identify one character at a position of a string from the set. Find the minimum 
// number of touches T Abhishek has to make so that he learn that all strings are different .
// Input Format:

// First line of input will contain T(number of test cases), each test case follows as.
// Line1: contain an integer N (number of strings)
// Next N line contain binary strings.

// Output Format:

// For each test case print the answer in newline.

// Constraints:

// 1 <= T <= 50
// 1 <= N <= 10
// 1 <= |S| <= 100 

// Sample Input :

// 1
// 2
// 111010
// 100100

// Sample Output :

// 2

// Explanation

// Abhishek touches 2nd bit from the start of both the binary string. 
// in the first touch (to string 1) he sees that the value is1.
// in the second touch (to string 2)he sees that the value is 0.
// so he concludes both strings are different in 2 touches.

#include<bits/stdc++.h>
using namespace std;

int f(int pos, int mask, vector<string>& v){
    
    
    if((mask&(mask-1))==0){
        return 0;
    }
    if(pos<0 ){
        return 10000;
    }
    
    
    int newmask1 = 0;
    int newmask2 = 0;
    int touches = 0;
    
    for(int i=0; i<v.size(); i++){
        
        if((mask&(1<<i))){
            touches++;
            if(v[i][pos]=='0'){
                newmask1 |= (1<<i);
            }
            else{
                newmask2 |= (1<<i);
            }
        }
    }
    
    int ans1 = f(pos-1, newmask1, v) + f(pos-1, newmask2, v) + touches;
    
    int ans2 = f(pos-1, mask, v);
    
    return min(ans1, ans2);
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> v;
        string s;
        for(int i=0; i<n; i++){
            cin>>s;
            v.push_back(s);
        }
        int len = v[0].size()-1;
        int mask = (1<<n)-1;
        int k = f(len,mask,v);
        cout<<k<<endl;
    }
    return 0;
}
