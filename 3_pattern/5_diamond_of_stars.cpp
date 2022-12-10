// Code : Diamond of stars
// Send Feedback
// Print the following pattern for the given number of rows.
// Note: N is always odd.

// Sample Input 1:
// 5
// Sample Output 1:
//   *
//  ***
// *****
//  ***
//   *

#include<iostream>
using namespace std;


int main() {
    
    /*  Read input as specified in the question.
     * Print output as specified in the question.
     */
    int n;
    cin>>n;
    n = (n/2)+1;
    
    int i = 1;
    int j = 1;
    
    while(i<=n){
        
        int spaces = n-i;
        
        while(spaces){
            cout<<" ";
            spaces--;
        }
        
        j = 2*i-1;
        while(j){
            cout<<"*";
            j--;
        }
        
        cout<<endl;
        
//         spaces = i;
//         while(spaces){
//             cout<<" ";
//             spaces--;
//         }
        
//         j = 2*(n-i)-1;
        
//         while(j){
//             cout<<"*";
//             j--;
//         }
//         cout<<endl;
        i++;
    }
    
    n = n - 1;
    i = 1;
    while(i<=n){
        
        int spaces = i;
        while(spaces){
            cout<<" ";
            spaces--;
        }
        
        j = 2*(n-i+1)-1;
        while(j){
            cout<<"*";
            j--;
        }
        
        cout<<endl;
        i++;
    }
    
    return 0;
}
