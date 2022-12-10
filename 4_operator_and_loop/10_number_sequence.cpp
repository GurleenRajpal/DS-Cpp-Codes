// Check Number sequence
// Send Feedback
// You are given S, a sequence of n integers i.e. S = s1, s2, ..., sn. Compute if it is possible to split S into two parts : 
// s1, s2, ..., si and si+1, si+2, ….., sn (0 <= i <= n) in such a way that the first part is strictly decreasing while the second is strictly increasing one.
// Note : We say that x is strictly larger than y when x > y.
// So, a strictly increasing sequence can be 1 4 8. However, 1 4 4 is NOT a strictly increasing sequence.


// That is, in the sequence if numbers are decreasing, they can start increasing at one point. Thereafter, they cannot decrease at any point further.
// Sequence made up of only increasing numbers or only decreasing numbers is a valid sequence. So, in both the cases, print true.


// You just need to print true/false. No need to split the sequence.
// Input format :
// Line 1 : Integer 'n'
// Line 2 and Onwards : 'n' integers on 'n' lines(single integer on each line)
// Output Format :
// "true" or "false" (without quotes)
// Constraints :
// 1 <= n <= 10^7
// Sample Input 1 :
// 5
// 9
// 8
// 4
// 5
// 6
// Sample Output 1 :
// true

#include<iostream>
using namespace std;

int main() {
	// Write your code here
    int t;
    cin>>t;
    int a[t];
    int j = 0;
    int n = t;
    
    while(n){
        cin>>a[j];
        j++;
        n--;
    }
    n = t;
    
    if(n==1){
        cout<<"true"<<endl;
        return 0;
    }
    
    if(n==2){
        if(a[0]==a[1]){
            cout<<"false"<<endl;
            return 0;
        }
    }
    // if only increasing
    int inc = 0;
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1]){
            inc = 1;
        }
        else{
            inc = 0;
            break;
        }
    }
    if(inc == 1){
        cout<<"true"<<endl;
        return 0;
    }

    //if only decreasing
	int dec = 0;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            dec = 1;
        }
        else{
            dec = 0;
            break;
        }
    }
    if(dec == 1){
        cout<<"true"<<endl;
        return 0;
    }
    
    //if decreasing then increasing
    int pivot = 0;
    for(int i=1;i<n-1;i++){
        if(a[i]<a[i-1] && a[i]<a[i+1]){
            pivot = i;
            break;
        }
    }
    
    if(pivot==0){
        cout<<"false"<<endl;
        return 0;
    }
    
    //increase from pivot
    int pt = pivot;
    inc = 1;
    for(int i=pt+1;i<n;i++){
        if(a[i]<a[i-1]){
            inc = 0;
            break;
        }
    }
    if(inc){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}
