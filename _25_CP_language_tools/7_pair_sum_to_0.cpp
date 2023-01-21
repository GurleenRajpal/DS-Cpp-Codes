// Pair sum to 0
// Send Feedback
// Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
// Note: Array A can contain duplicate elements as well.
// Input format:
// The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
// The following line contains N space separated integers, that denote the value of the elements of the array.
// Output format :
// The first and only line of output contains the count of pair of elements in the array which sum up to 0. 
// Constraints :
// 0 <= N <= 10^4
// Time Limit: 1 sec
// Sample Input 1:
// 5
// 2 1 -2 2 3
// Sample Output 1:
// 2

#include<unordered_map>
int pairSum(int *arr, int n) {
	// Write your code here
    unordered_map<int, int> mp;
    int numZeros = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            numZeros++;
            continue;
        }
        mp[arr[i]]++;
        //cout<<arr[i]<<" "<<mp[arr[i]]<<endl;
    }
    
    unordered_map<int, int>::iterator itr;
    int count = 0;
    
    count+= (numZeros*(numZeros-1));
    
    
    for(itr = mp.begin(); itr!=mp.end(); ++itr){
        //cout<<"Here"<<itr->first<<" "<<itr->second<<endl;
        // if(mp[-1*itr->first]>0){
        //     count+= itr->second;
        // }
        if(mp.count(-1*itr->first)){
            //cout<<itr->second<<endl;
            count+= mp[-1*itr->first] * itr->second;
        }
    }
    
    return count/2;
    
}
