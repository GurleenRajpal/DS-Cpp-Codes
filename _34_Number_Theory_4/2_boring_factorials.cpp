// Boring Factorials
// Send Feedback
// Sameer and Arpit want to overcome their fear of Maths and so they have been 
// recently practising Maths problems a lot. Aman, their friend has been helping them out. 
// But as it goes, Sameer and Arpit have got bored with problems involving factorials. Reason being,
// the factorials are too easy to calculate in problems as they only require the residue modulo 
// some prime and that is easy to calculate in linear time. So to make things interesting for them, 
// Aman - The Mathemagician, gives them an interesting task. He gives them a prime number P and an 
// integer N close to P, and asks them to find N! modulo P. He asks T such queries.
// Input Format:
// First line contains an integer T, the number of queries asked.
// Next T lines contains T queries of the form “N P”. (quotes for clarity)
// Output Format:
// Output exactly T lines, containing N! modulo P.
// Constraints:
// 1 <= T <= 1000
// 1 < P <= 2*10^9
// 1 <= N <= 2*10^9
// Abs(N-P) <= 1000
// Sample Input:
// 3
// 2 5
// 5 11
// 21 71
// Sample Output:
// 2
// 10
// 6

#include<bits/stdc++.h>
using namespace std;

long long ex(long long i, long long n, int p){
    if(n==0){
        return 1;
    }
    if(n%2==0){
        long long smallAns = ex(i, n/2, p);
        return (smallAns%p * smallAns%p)%p;
    }
    else{
        long long smallAns = (i%p * ex(i, n-1, p));
        return smallAns%p;
    }
    
    
}


int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int p, n;
        cin>>n>>p;
        if(p==0){
            cout<<1<<endl;
            continue;
        }
        if(n>=p){
            cout<<0<<endl;
            continue;
        }
        int ans = -1;
        
        for(int i=n+1; i<=p-1; i++){
            ans  = (ans * ex(i, p-2, p))%p;
        }
        
        //ans *=-1;
        ans += p;
        cout<<ans<<endl;
        
        
        
    }
    return 0;
}
