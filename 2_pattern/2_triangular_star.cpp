// Print the following pattern for the given N number of rows.
// Pattern for N = 4

// *
// **
// ***
// ****

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
        j = 1;
        while(j<=i){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
}
