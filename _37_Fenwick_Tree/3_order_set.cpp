// OrderSet - Problem
// Send Feedback
// In this problem, you have to maintain a dynamic set of numbers which support the two fundamental operations
// INSERT(S,x): if x is not in S, insert x into S
// DELETE(S,x): if x is in S, delete x from S
// and the two type of queries
// K-TH(S) : return the k-th smallest element of S
// COUNT(S,x): return the number of elements of S smaller than x
// Input Format:
// Line 1: Q , the number of operations
// In the next Q lines, the first token of each line is a character I, D, K or C meaning that the 
// corresponding operation is INSERT, DELETE, K-TH or COUNT, respectively, following by a whitespace 
// and an integer which is the parameter for that operation.
// Constraints:
// 1 <= Q <= 2*10^5
// -10^9 <= x <= 10^9
// Output Format:
// For each query, print the corresponding result in a single line. In particular, for the queries K-TH, if 
// k is larger than the number of elements in S, print the word 'invalid'.
// Sample Input 1:
// 8
// I -1
// I -1
// I 2
// C 0
// K 2
// D -1
// K 1
// K 2
// Sample Output 1:
// 1
// 2
// 2
// invalid

#include<bits/stdc++.h>
#define MAX 200010
using namespace std;

void update(int idx, int val, int* bit){
    for(;idx<MAX; idx+=(idx&(-idx))){
        bit[idx]+=val;
    }
}

int query(int idx, int* bit){
    int sum = 0;
    for(;idx>0; idx-=(idx&(-idx))){
        sum+=bit[idx];
    }
    return sum;
}


int main(){
    
    // write your code here
    int q;
    cin>>q;
    
    char c[MAX];
    int a[MAX];
    
    int* t = new int[MAX]();
    // pair<int, int>* mp = new pair<int,int>[MAX];
    unordered_map<int, int> mp;
    //reverse map
    unordered_map<int, int> rmap;
    int* bit = new int[MAX]();
    
    int x = 0;
    
    for(int i=0; i<q; i++){
        cin>>c[i]>>a[i];
        if(c[i]=='I'){
            t[x] = a[i];
            x++;
        }
    }
    
    sort(t, t+x);
    int idx = 1;
    for(int i=0; i<x; i++){
        if(t[i]!=t[i+1]){
            // cout<<t[i]<<endl;
            mp[t[i]] = idx;
            rmap[idx] = t[i];
            idx++;
        }
    }
    // cout<<"here"<<endl;
    for(int i=0; i<q; i++){
        if(c[i]=='I'){
            if(query(mp[a[i]], bit)==query(mp[a[i]]-1, bit)){
                //a[i] is not inserted
                update(mp[a[i]], 1, bit);
            }
        }
        else if(c[i]=='D'){
            if(query(mp[a[i]], bit)!=query(mp[a[i]]-1, bit)){
                //a[i] is not inserted
                update(mp[a[i]], -1, bit);
            }
        }
        else if(c[i]=='C'){
            //lower bound in t[i]
            int f = lower_bound(t,t+x,a[i])-t;
            
            f--;
            cout<<query(mp[t[f]], bit)<<endl;
        }
        else if(c[i]=='K'){
            int v = a[i];
            // cout<<a[i]<<endl;
            int low = 1;
            int high = MAX-1;
            int ans = 1e9;
            bool res = false;
            while(low<=high){
                int mid = (high+low)/2;
                if(query(mid, bit)==v){
                    ans = min(ans, mid);
                    res = true;
                    high = mid-1;
                }
                else if(query(mid, bit)>v){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
                // cout<<mid<<" "<<query(mid, bit)<<endl;
            }
            if(!res){
                cout<<"invalid"<<endl;
            }
            else{
                cout<<rmap[ans]<<endl;
            }
        }
    }
    
    return 0;
}
