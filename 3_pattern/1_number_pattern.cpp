// Code : Mirror Number Pattern
// Send Feedback
// Print the following pattern for the given N number of rows.
// Pattern for N = 4
// ...1
// ..12
// .123
// 1234

// The dots represent spaces.

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
        
        int j = 1;
        while(j<=i){
            cout<<j;
            j++;
        }
        cout<<endl;
        i++;
    }
  
}


