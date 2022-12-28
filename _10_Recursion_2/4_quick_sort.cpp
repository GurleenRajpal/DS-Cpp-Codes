// Quick Sort Code
// Send Feedback
// Sort an array A using Quick Sort.
// Change in the input array itself. So no need to return or print anything.


// Input format :
// Line 1 : Integer n i.e. Array size
// Line 2 : Array elements (separated by space)
// Output format :
// Array elements in increasing order (separated by space)
// Constraints :
// 1 <= n <= 10^3
// Sample Input 1 :
// 6 
// 2 6 8 5 4 3
// Sample Output 1 :
// 2 3 4 5 6 8
// Sample Input 2 :
// 5
// 1 5 2 7 3
// Sample Output 2 :
// 1 2 3 5 7 


int partition(int input[], int si, int ei){
    int x = input[si];
    int l = 0;
    for(int i=si+1;i<=ei;i++){
        if(x>=input[i]){
            l++;
        }
    }

    int temp = input[si+l];
    input[si+l] = input[si];
    input[si] = temp;
    
    
    int i = si;
    int j = ei;
    int m = si+l;
    while(i<=m && j>=m){
        if(input[i]<=x){
            i++;
        }
        else if(input[j]>x){
            j--;
        }
        else{
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }
    return m;
}

void quickS(int input[], int si, int ei){
    
    if(si>=ei){
        return;
    }
    int c = partition(input, si, ei);
 
    quickS(input, si, c-1);
    quickS(input, c+1, ei);
    
    
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    quickS(input, 0, size-1);

}

#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}



