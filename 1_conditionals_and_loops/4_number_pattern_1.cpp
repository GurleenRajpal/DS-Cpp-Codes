// Print the following pattern

// Pattern for N = 4
// 1
// 23
// 345
// 4567

#include <iostream>
using namespace std;

int main(){

    /*  Read input as specified in the question.
    *   Print output as specified in the question.
    */
	
    int n;
    cin >> n;
    int i = 1, j = 1, k = 1;
	
    while(i <= n){
        k = i;
        j = 1;
	    
        while(j <= i){
            cout << k;
            k++;
            j++;
        }
        cout << endl;
        i++;
    }
   return 0;
}


