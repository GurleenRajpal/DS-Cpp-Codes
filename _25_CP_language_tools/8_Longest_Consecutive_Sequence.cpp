// Longest Consecutive Sequence
// Send Feedback
// You are given an array of unique integers that contain numbers in random order. You have 
// to find the longest possible sequence of consecutive numbers using the numbers from given array.
// You need to return the output array which contains starting and ending element. If the length of 
// the longest possible sequence is one, then the output array must contain only single element.
// Note:
// 1. Best solution takes O(n) time.
// 2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.
// Input format:
// The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
// The following line contains n space separated integers, that denote the value of the elements of the array.
// Output format:
// The first and only line of output contains starting and ending element of the longest consecutive sequence. If 
// the length of longest consecutive sequence, then just print the starting element.
// Constraints :
// 0 <= n <= 10^6
// Time Limit: 1 sec
// Sample Input 1 :
// 13
// 2 12 9 16 10 5 3 20 25 11 1 8 6 
// Sample Output 1 :
// 8 12 
// Sample Input 2 :
// 7
// 3 7 2 1 9 8 41
// Sample Output 2 :
// 7 9
// Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length 
// i.e. [1, 2, 3] and [7, 8, 9], but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes 
// first in input array and therefore, the output will be 7 9, as we have to print starting and ending element 
// of the longest consecutive sequence.
// Sample Input 3 :
// 7
// 15 24 23 12 19 11 16
// Sample Output 3 :
// 15 16
#include <iostream>
#include <vector>
using namespace std;

#include<unordered_map>
#include<vector>
#include<algorithm>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_map<int, int> mp;
    
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    vector<int> v, finalV;
    
    int len = 0, finalLen = 0;
    
    unordered_map<int, int>::iterator itr;
    int j = 0;
    
    for(int i=0; i<n; i++){
    	v.clear();
        int k = arr[i];
        len = 0;
        while(mp[k]>0){
            v.push_back(k);
            k++;
            len++;
        }
        k = arr[i]-1;
        while(mp[k]>0){
            v.push_back(k);
            k--;
            len++;
        }
        
        if(len>finalLen){
            finalV = v;
            finalLen = len;
        }
        
        if(len==finalLen){
            sort(finalV.begin(), finalV.end());
            sort(v.begin(), v.end());
            int index1 = -1;
            int index2 = -1;
            for(int i=0;i<n;i++){
                if(finalV[0]==arr[i])index1 = i;
                if(v[0]==arr[i]) index2 = i;
            }
            if(index1>index2){
                finalV = v;
            }
            
        }
    }
    vector<int> vx;
    sort(finalV.begin(), finalV.end());
    vx.push_back(finalV[0]);
    vx.push_back(finalV[finalLen-1]);
    return vx;
}



int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
