// Segmented Sieve Problem
// Send Feedback
// In this problem you have to print all primes from given interval.
// Input Format:
// First line of input will contain T(number of test cases), each test case follows as.

// On each line are written two integers L and U separated by a blank. L - lower bound of 
// interval, U - upper bound of interval.
// Output Format:
// For each test case output must contain all primes from interval [L; U] in increasing order.
// Constraints:
// 1  <= T <= 100
// 1 <= L <= U <= 10^9
// 0 <= U - L <= 10^5
// Sample Input:
// 2
// 2 10
// 3 7
// Sample Output:
// 2 3 5 7
// 3 5 7 


#include<bits/stdc++.h>
using namespace std;
void sieve(vector<long long>& primes){
    int n = 100001;
    vector<bool> v(n+1, true);
    v[0] = false;
    v[1] = false;
    
    for(int i=2; i*i<=n; i++){
        if(v[i]==false){
            continue;
        }
        for(int j=i*i; j<=n; j+=i){
            if(j%i==0){
                v[j] = false;
            }
        }
    }
    primes.push_back(2);
    for(int i=3; i<=n; i++){
        if(v[i]){
            primes.push_back(i);
        }
    }
    return;
}

void printPrimes(vector<long long>primes,long long l,long long u){
    int n = u-l;
    bool a[n+1];
    for(int i=0; i<=n; i++){
        a[i] = true;
    }
    
    for(long long i=0; primes[i]*primes[i]<=u; i++){
        long long currPrime = primes[i];
        long long base = (l/currPrime)*currPrime;
        
        if(base<l){
            base = base + currPrime;
        }
        
        for(long long j = base; j<=u; j+=currPrime){
            a[j-l] = false;
        }
        
        if(base==currPrime){
            a[base-l] = true; 
        }
    }
    if(l==1){
        a[0] = false;
    }
    for(long long i=0; i<=n; i++){
        if(a[i]){
            cout<<l+i<<" ";
        }
    }
    cout<<endl;
    
}


int main(){
    
    // write your code here
    vector<long long> primes;
    sieve(primes);
    
    int t;
    cin>>t;
    while(t--){
        long long l, u;
        cin>>l>>u;
        printPrimes(primes, l, u);
    }
    
    
    return 0;
}
