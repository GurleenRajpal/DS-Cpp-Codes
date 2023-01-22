// Legion of Doom
// Send Feedback
// Lex Luthor’s Legion of Doom is a tough organization to get into, even for greatest supervillains. 
// Recently, a spot has opened up because The Mad Hatter has retired. Harley Quinn doesn't want to waste 
//   this opportunity, and jumps at the chance of the interview. But she has a PhD in psychology, not in 
//   Computer Science. She has kidnapped you and will let you go only if you are able to solve the evil questions of Lex Luthor.
// You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
// 0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.
// 1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
// Input Format:
// In the first line you'll be given T, number of test cases.

// Each test case will start with N and C. After that you'll be given C commands in the format as mentioned above
// Constraints:
//  1 <= T <= 10
//  1 <= N, C <= 10000
//  1 <= val <= 10^8
//  1 <= p <= q <= N
// Output Format:
// Print the answers of the queries in new line for each test case.
// Sample Input 1:
// 1
// 8 6
// 0 2 4 26
// 0 4 8 80
// 0 4 5 20
// 1 8 8 
// 0 5 7 14
// 1 4 8
// Sample Output 1:
// 80  
// 508

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void update_lazy(ll* tree, ll* lazy, ll low, ll high, ll currPos, ll startR, ll endR, ll inc){
    //if(low>high) return;
    if(lazy[currPos]!=0){
        tree[currPos] += (high-low+1)*lazy[currPos];
        if(low!=high){
            lazy[2*currPos] += lazy[currPos];
            lazy[2*currPos+1] += lazy[currPos];
        }
        lazy[currPos] = 0;
    }
    if(startR>high || endR<low){
        return;
    }
    if(startR<=low && endR>=high){
        tree[currPos]+=inc*(high-low+1);
        if(low!=high){
            lazy[2*currPos]+=inc;
            lazy[2*currPos+1]+=inc;
        }
        return;
    }
    ll mid = (low+high)/2;
    update_lazy(tree, lazy, low, mid, 2*currPos, startR, endR, inc);
    update_lazy(tree, lazy, mid+1, high, 2*currPos+1, startR, endR, inc);
    tree[currPos] = tree[2*currPos]+tree[2*currPos+1];
    return;
}

long long query(long long* tree, long long* lazy, ll low, ll high, ll currPos, ll startR, ll endR){
    if(low>high) return 0;
    if(lazy[currPos]!=0){
        tree[currPos] += lazy[currPos]*(high-low+1);
        if(low!=high){
            lazy[2*currPos] += lazy[currPos];
            lazy[2*currPos+1] += lazy[currPos];
        }
        lazy[currPos] = 0;
    }
    if(startR>high || endR<low){
        return 0;
    }
    if(startR<=low && endR>=high){
        return tree[currPos];
    }
    ll mid = (low+high)/2;
    ll ans1 = query(tree, lazy, low, mid, 2*currPos, startR, endR);
    ll ans2 = query(tree, lazy, mid+1, high, 2*currPos+1, startR, endR);
    
    return ans1+ans2;
    
}


int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        long long n, q;
        cin>>n>>q;
        long long* tree = new long long[4*n]();
        long long* lazy = new long long[4*n]();
        
        
        while(q--){
            int k;
            cin>>k;
            if(k==0){
            	int p, q, val;
                cin>>p>>q>>val;
                update_lazy(tree, lazy, 0, n-1, 1, p-1, q-1,val);
            }
            if(k==1){
                int p, q;
                cin>>p>>q;
                cout<<query(tree, lazy, 0, n-1, 1, p-1, q-1)<<endl;
            }
        }
        
    }
    return 0;
}
