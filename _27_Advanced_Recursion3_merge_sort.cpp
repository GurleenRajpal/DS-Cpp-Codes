// Merge Sort Code
// Send Feedback
// Sort an array A using Merge Sort.
// Change in the input array itself. So no need to return or print anything.
// Input format :
// First line of input will contain T number of test cases
// First line of every input will contain a single integer N size of the input array.
// second line of each input will contain N space-separated integers.
// Output format :
// For every test case print, array elements in increasing order (separated by space) in a separate line.
// Constraints :
// 1 <= T <= 10
// 1 <= n <= 10^5
// Sample Input 1 :
// 1
// 6 
// 2 6 8 5 4 3
// Sample Output 1 :
// 2 3 4 5 6 8
// Sample Input 2 :
// 1
// 5
// 2 1 5 2 3
// Sample Output 2 :
// 1 2 2 3 5 

#include<bits/stdc++.h>
using namespace std;

void merge(int*a, int si, int mid, int ei){
    int i = si;
    int j = mid+1;
    
    int* temp = new int[ei-si+1];
    int k = 0;
    while(i<=mid && j<=ei){
        if(a[i]<a[j]){
            temp[k] = a[i];
            i++;
            k++;
        }
        else{
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    
    while(i<=mid){
        temp[k] = a[i];
        i++;
        k++;
    }
    while(j<=ei){
        temp[k] = a[j];
        j++;
        k++;
    }
    
    i = si;
    int len = ei-si+1;
    k = 0;
    while(k<len){
        a[i] = temp[k];
        i++;
        k++;
    }
    delete [] temp;
    
}

void mergeSort(int* a, int si, int ei){
    if(si>=ei){
        return;
    }
    int mid = si+(ei-si)/2;
    mergeSort(a, si, mid);
    mergeSort(a, mid+1, ei);
    merge(a, si, mid, ei);
    
}


int main(){
    
    // write your code here
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        
        mergeSort(a, 0, n-1);
        
        for(int i=0; i<n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
