// Card Game
// Send Feedback
// Vova again tries to play some computer card game.
// The rules of deck creation in this game are simple. Vova is given an existing deck of n cards and 
// a magic number k. The order of the cards in the deck is fixed. Each card has a number written on it; 
// number ai is written on the i-th card in the deck.
// After receiving the deck and the magic number, Vova removes x (possibly x = 0) cards from the top of the deck, 
// y (possibly y = 0) cards from the bottom of the deck, and the rest of the deck is his new deck (Vova has to 
// leave at least one card in the deck after removing cards). So Vova's new deck actually contains cards x + 1, 
// x + 2, ... n - y - 1, n - y from the original deck.
// Vova's new deck is considered valid iff the product of all numbers written on the cards in his new deck is 
// divisible by k. So Vova received a deck (possibly not a valid one) and a number k, and now he wonders, 
// how many ways are there to choose x and y so the deck he will get after removing x cards from the top and y cards from the bottom is valid?
// Input
// The first line contains two integers n and k (1 ≤ n ≤ 100 000, 1 ≤ k ≤ 10^9).

// The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 10^9) — the numbers written on the cards.
// Output
// Print the number of ways to choose x and y so the resulting deck is valid.
// Sample Input 1
// 3 4
// 6 2 8
// Sample Output 1
// 4
// Sample Input 2
// 3 6
// 9 1 14
// Sample Output 2
// 1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	// Write your code here
    long long n, k, ans= 0;
    cin>>n>>k;
    long long* a = new long long[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    //find divisors of k
    vector<pair<int, int>> divisors;
    //f(divisors, k);
    long long temp = k;
    for(int i=2; i*i<=temp; i++){
        if(temp%i==0){
            int count = 0;
            while(temp%i==0){
                temp = temp/i;
                count++;
            }
            divisors.push_back(make_pair(i, count));
        }
    }
    if(temp!=1){
        divisors.push_back(make_pair(temp,1));
    }
    // for(int i=0; i<divisors.size(); i++){
    //     cout<<divisors[i].first<<" ";
    // }
    
    vector<pair<int, int>> divisors2 = divisors;
    
    for(int i=0; i<divisors2.size(); i++){
        divisors2[i].second = 0;
    }
    
    int j = 0;
    for(int i=0; i<n; i++){
        
        for(int z= 0 ; z<divisors.size(); z++){
            if(a[i]%divisors[z].first==0){
                int x = a[i];
                int count = 0;
                while(x%divisors[z].first==0){
                    x = x / divisors[z].first;
                    count++;
                }
                divisors2[z].second += count;
            }
        }
        
        while(j<=i){
            int z;
            for(z=0; z<divisors.size(); z++){
                if(divisors[z].second>divisors2[z].second){
                    break;
                }
            }
            if(z!=divisors.size()){
                break;
            }
            ans += n-i;
            //cout<<n-i<<" i : "<<i<< " j : "<<j<<endl;
            for(int r = 0; r<divisors.size(); r++){
                if(a[j]%divisors[r].first==0){
                    int x = a[j];
                    int count = 0;
                    while(x%divisors[r].first==0){
                        x = x/divisors[r].first;
                        count++;
                    }
                    divisors2[r].second -= count;
                }
            }
            j++;
            
        }
    }
    
    cout<<ans<<endl;
    
    
	return 0;
}
