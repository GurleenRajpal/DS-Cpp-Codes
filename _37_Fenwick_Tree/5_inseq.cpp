// INCSEQ
// Send Feedback
// Given a sequence of N integers S1, ..., SN, compute the number of increasing subsequences of
// S with length K and that is, the number of K-tuples i1, ..., iK such that 1 ≤ i1 < ... < iK ≤ N and Si1 < ... < SiK.
// Input Format:
// The first line contains the two integers N and K. 
// Next line contains N space-separated integers denoting the elements of the array.
// Constraints:
//  1 <= N <= 10^4
//  1 <= K <= 50
//  1 <= arr[i] <= 10^5
// Output Format:
// Print a single integer representing the number of increasing subsequences of S of length K, modulo 5,000,000.
// Sample Input 1:
// 4 3
// 1 2 2 10
// Sample Output 1:
// 2

#include<bits/stdc++.h>
using namespace std;
#define max 100005

int mod = 5000000;
void update(int idx, int len, int val, int tree[51][max]){
    for(; len<max; len+=(len&(-len))){
        tree[idx][len] = (tree[idx][len]%mod + val%mod)%mod;
    }
}

int query(int idx, int len, int tree[51][max]){
    int sum = 0;
    for(;len>0; len-=(len&(-len))){
        sum= sum + tree[idx][len]%mod;
    }
    return sum%mod;
}

void compress(int* a, int n){
    unordered_map<int, int> mp;
    int* b = new int[n+1];
    for(int i=1; i<=n; i++){
        b[i] = a[i];
    }
    sort(b+1, b+n+1);
    int idx = 1;
    for(int i=1; i<=n; i++){
        if(mp[b[i]]==0){
            mp[b[i]] = idx;
            idx++;
        }
    }
    for(int i=1; i<=n; i++){
        a[i] = mp[a[i]];
    }
}



int main(){
    
    // write your code here
    int n, k;
    cin>>n>>k;

    int tree[51][max];
    for(int i=0; i<51; i++){
        for(int j=0; j<max; j++){
            tree[i][j] = 0;
        }
    }

    int* a =new int[n+1];

    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    compress(a, n);
    // for (int i = 1; i <= n; i++) {
    //   cout<< a[i]<<" ";
    // }cout<<endl;
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            int p;
            if(j==1) p = 1;
            else p = query(j-1,a[i]-1, tree );
            update(j, a[i], p, tree);
            if(j==k){
                ans = (ans+p)%mod;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
