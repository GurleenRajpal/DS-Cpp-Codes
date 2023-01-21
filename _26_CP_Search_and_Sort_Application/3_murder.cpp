// Murder
// Send Feedback
// Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs 
// and saw that a number is written on every stair. He found it suspicious and decides to remember all 
// the numbers that he has seen till now. While remembering the numbers he found that he can find some 
// pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of 
// all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum 
// of all the numbers written on his notes diary.
// Answer may not fit in integer . You have to take long.
// Input Format:
// First line of input contains an integer T, representing number of test case.
// For each test case, first line of input contains integer N, representing the number of stairs.
// For each test case, second line of input contains N space separated integers, representing numbers written on the stairs.
// Constraints
// T<=10^5
// 1<=N<=10^5
// All numbers will be between 0 and 10^9
// Sum of N over all test cases doesn't exceed 5*10^5
// Output Format
// For each test case output one line giving the final sum for each test case.
// Sample Input 1:
// 1
// 5
// 1 5 3 6 4
// Sample Output 1:
// 15
// Explanation:
// For the first number, the contribution to the sum is 0.
// For the second number, the contribution to the sum is 1.
// For the third number, the contribution to the sum is 1.
// For the fourth number, the contribution to the sum is 9 (1+5+3).
// For the fifth number, the contribution to the sum is 4 (1+3).
// Hence the sum is 15 (0+1+1+9+4).

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll merge(long long* a,ll si, ll mid, ll ei){
    ll i = si;
	ll j = mid+1;
    
    ll* newArr = new ll[ei-si+1];
    
    ll val = 0;
    ll k = 0;
    while(i<=mid && j<=ei){
        if(a[i]<a[j]){
            val += a[i]*(ei-j+1);
            newArr[k] = a[i];
            i++;
            k++;
        }
        else{
            newArr[k] = a[j];
            j++;
            k++;
        }
    }
    
    while(i<=mid){
        newArr[k] = a[i];
        i++;
        k++;
    }
    
    while(j<=ei){
        newArr[k] = a[j];
        j++;
        k++;
    }
    
    
    i = si;
    k = 0;
    while(i<=ei){
        a[i] = newArr[k];
        i++;
        k++;
    }
    
    delete[] newArr;
    
    return val;
}

ll mergeSort(ll* a, ll si, ll ei){
    if(si>=ei){
        return 0;
    }
    ll mid = (si+ei)/2;
    ll left = mergeSort(a, si, mid);
    ll right = mergeSort(a, mid+1, ei);
    
    ll v = merge(a, si, mid, ei);
    
    return left+right+v;
}
int main(){
    // write your code
	int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        
        ll a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        cout<<mergeSort(a, 0, n-1)<<endl;
    }
    return 0;
}
