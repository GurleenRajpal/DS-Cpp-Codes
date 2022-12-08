// Print the following pattern
// Pattern for N = 4
// ...1
// ..23
// .345
// 4567
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
    int k = 1;
    int l = 1;
    while(i<=n){
        k = i;
        j = 1;
        l = n-i;
        while(l){
            cout<<" ";
            l--;
        }
        while(j<=i){
            cout<<k;
            j++;
            k++;
        }
        cout<<endl;
        i++;
    }
}
