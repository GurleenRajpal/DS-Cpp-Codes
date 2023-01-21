// Quick Sort Code
// Send Feedback
// Sort an array A using Quick Sort.
// Change in the input array itself. So no need to return or print anything.


// Input format :
// First line will contain T number of test case and each tet case will consist of two lines.
// Line 1 : Integer n i.e. Array size
// Line 2 : Array elements (separated by space)
// Output format :
// for every test case print rray elements in increasing order (separated by space) in a new line.
// Constraints :
// 1 <= T <= 10
// 1 <= n <= 10^5
// 0 <= arr[i] <= 10^9
// Sample Input 1 :
// 1
// 6 
// 2 6 8 5 4 3
// Sample Output 1 :
// 2 3 4 5 6 8
// Sample Input 2 :
// 1
// 5
// 1 5 2 7 3
// Sample Output 2 :
// 1 2 3 5 7 

#include<bits/stdc++.h>
using namespace std;

int partition(int* a, int si, int ei){
    
    int index = si;
    int k = a[si];
    int smaller_element = 0;
    
    for(int i = si+1; i<=ei; i++){
        if(k>=a[i]){
            smaller_element++;
        }
    }
    
    swap(a[si], a[si+smaller_element]);
    
    int position = si+smaller_element;
    k = a[position];
    int i = si;
    int j = ei;
    
    while(i<=position && j>=position){
        while(a[i]<=k){
            i++;
        }
        while(a[j]>k){
            j--;
        }
        if(i<position && j>position){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    
    return position;
    
}
void quickSort(int* a, int si, int ei){
    if(si>=ei)return;
    
    int c = partition(a, si, ei);
    
    quickSort(a, si, c-1);
    quickSort(a, c+1, ei);
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        
        quickSort(a,0, n-1);
        
        for(int i=0; i<n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
