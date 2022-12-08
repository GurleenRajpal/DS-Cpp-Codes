// Print the following pattern
// Pattern for N = 4

// ...*
// ..***
// .*****
// *******



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
    int k = 1;
    
    while(i<=n){
        k = n-i;
        while(k){
            cout<<" ";
            k--;
        }
        j = 2*(i-1)+1;
        while(j){
            cout<<"*";
            j--;
        }
        cout<<endl;
        i++;
    }
}


