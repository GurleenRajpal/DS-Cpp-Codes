// Sachin And Varun Problem
// Send Feedback
// Varun and you are talking about a movie that you have recently watched while Sachin is busy teaching Number Theory. 
// Sadly, Sachin caught Varun talking to you and asked him to answer his question in order to save himself from punishment. The question says:
// Given two weights of a and b units, in how many different ways you can achieve a weight of d units using only 
// the given weights? Any of the given weights can be used any number of times (including 0 number of times).
// Since Varun is not able to answer the question, he asked you to help him otherwise he will get punished.
// Note: Two ways are considered different if either the number of times a is used or a number of times b is used is different in the two ways.
// Input Format:
// The first line of input consists of an integer 
// T denoting the number of test cases.
// Each test case consists of only one line containing three space-separated integers a, b and d.
// Output Format:
// For each test case, print the answer in a separate line.
// Constraints:
// 1 ≤ T ≤ 10 ^ 5

// 1 ≤ a < b ≤ 10 ^ 9

// 0 ≤ d ≤ 10 ^ 9
// Sample Input 1
// 4
// 2 3 7
// 4 10 6
// 6 14 0
// 2 3 6
// Sample Output 1
// 1
// 0
// 1
// 2
// Explanation
// Test case 1: 7 can only be achieved by using 2 two times and 3 one time.

// Test case 2: 6 can't be achieved by using 4 and 10. So, 0 ways are there.

#include<bits/stdc++.h>
using namespace std;

class Triplet{
    public:
    	long long x;
    	long long y;
    	long long gcd;
};


Triplet extendedEuclid(long long a, long long b){
    if(b==0){
        Triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }
    
    Triplet smallAns = extendedEuclid(b, a%b);
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    
    return ans;
    
}

long long mmInverse(long long a,long long m){
    Triplet ans = extendedEuclid(a,m);
    long long lx = ans.x;
    return (lx%m+m)%m;
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        long long a,b,d;
        cin>>a>>b>>d;
        
        long long g = __gcd(a, b);
        if(d%g!=0){
            cout<<0<<endl;
            continue;
        }
        
        a/=g;
        b/=g;
        d/=g;
        
        long long mm = mmInverse(b,a);
        
        long long y = (d%a * mm)%a;
        if(y<0 || y*b>(d)){
            cout<<0<<endl;
            continue;
        }
        
        long long n = (d/b - y) / a;
        
        cout<<n+1<<endl;
    }
    return 0;
}
