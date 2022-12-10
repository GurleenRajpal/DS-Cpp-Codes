// Number Star Pattern
// Send Feedback
// Print the following pattern for given number of rows.
// Input format :

// Line 1 : N (Total number of rows)

// Sample Input :
//    5
// Sample Output :
// 1234554321
// 1234**4321
// 123****321
// 12******21
// 1********1
  
#include<iostream>
using namespace std;


int main(){

  // Write your code here
	int n;
    cin>>n;
    int i = 1;
    int j = 1;
    
    while(i<=n){
        j = (n-i)+1;
        int k = 1;
        while(j){
            cout<<k;
            k++;
            j--;
        }
        int stars = 2 * (i-1);
        
        while(stars){
            cout<<"*";
            stars--;
        }
        
        j = (n-i)+1;
        k = j;
        while(j){
            cout<<k;
            k--;
            j--;
        }
        
        cout<<endl;
        
        i++;
        
        
    }
    
    return 0;
}


