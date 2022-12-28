// Merge Sort Code
// Send Feedback
// Sort an array A using Merge Sort.
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
// 2 1 5 2 3
// Sample Output 2 :
// 1 2 2 3 5 

#include<iostream>
using namespace std;
void merge(int input[], int si,int mid, int ei){
    if(si>=ei)return;
    int len = ei-si+1;
    
    // int mid = (si+ei)/2;
    
    int a[len]={0};
    // cout<<"Len "<<len<<endl;
    int len1 = mid - si +1;
    int len2 = ei-mid;
    int i = si;
    int j = mid+1;
    int k = 0;
    while(i<mid+1 && j<=ei){
        if(input[i]<input[j]){
            a[k] = input[i];
            i++;
        }
        else{
            a[k] = input[j];
            j++;
        }
        k++;
    }
    while(i<mid+1){
        a[k] = input[i];
        i++;
        k++;
    }
    
    while(j<=ei){
        a[k] = input[j];
        k++;
        j++;
    }
     // cout<<"Array - ";

    for(int m=0;m<len;m++){
        input[si+m] = a[m];
        // cout<<a[m]<<" ";
        // cout<<input[m]<<" ";
    }
    // cout<<endl;
    // cout<<endl;
    
}

void mergeSort2(int input[], int si, int ei){
    
    
    if(si>=ei){
       
        return;
    }
    
    int mid = (si+ei)/2; 
    // cout<<si<<" "<<ei<<" "<<mid<<endl;
    mergeSort2(input, si, mid);
    
    mergeSort2(input, mid+1, ei);
    // cout<<"Called"<<endl;
    merge(input, si, mid, ei);
    
}

void mergeSort(int input[], int size){
	// Write your code here
    mergeSort2(input, 0, size-1);
}


#include <iostream>
using namespace std;

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
