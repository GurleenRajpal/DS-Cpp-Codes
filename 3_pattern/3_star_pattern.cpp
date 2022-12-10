// Code : Star Pattern
// Send Feedback
// Print the following pattern

// Sample Input 1 :
// 3
// Sample Output 1 :
//    *
//   *** 
//  *****

#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    int n;
    cin>>n;
    int i = 1;
    int j = 1;
    
    while(i<=n){
        int spaces = n-i;
        while(spaces){
            cout<<" ";
            spaces--;
        }
        j = i;
        while(j){
            cout<<"*";
            j--;
        }
        j = i-1;
        while(j){
            cout<<"*";
            j--;
        }
        cout<<endl;
        i++;
    }
  
}


