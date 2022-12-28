// Print Subset Sum to K
// Send Feedback
// Given an array A and an integer K, print all subsets of A which sum to K.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important. Just print them in different lines.
// Input format :
// Line 1 : Size of input array
// Line 2 : Array elements separated by space
// Line 3 : K 
// Sample Input:
// 9 
// 5 12 3 17 1 18 15 3 17 
// 6
// Sample Output:
// 3 3
// 5 1

#include<iostream>
#include<vector>
using namespace std;
void psoa(int input[], int size, int k, vector<int> v){
    if(k==0){
        for(int i=0;i<v.size();i++){
            cout<<v.at(i)<<" ";
        }
        cout<<endl;
        return;
    }
    
    if(size==0){
        return;
    }
    
    psoa(input+1, size-1, k, v );
    
    v.push_back(input[0]);
    
    psoa(input+1, size-1, k - input[0], v);
}


void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int output[1000][50];
    vector<int> v;
    psoa(input, size, k, v);
}


int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
