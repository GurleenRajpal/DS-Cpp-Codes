// Coder's Rating
// Send Feedback
// Some of the more elite (and not-so-elite) coders around take part in a certain unnamed 
// programming contest. In said contest, there are multiple types of competitions. Here, we 
// consider the Open and High School competition types. For each type, each competitor receives 
// a rating, an integer between 1 and 100000, inclusive. A coder's rating is based upon his or her
// level of performance in matches and is calculated using a complicated formula which, thankfully, you will not be asked to implement.
// Although the Open and High School ratings for a coder who has participated in both competition 
// types lately are usually close, this is not always the case. In particular, High School matches
// are more about speed, since many coders are able to solve all the problems, whereas Open matches 
// require more thinking and there is a steeper curve in terms of problem difficulty.
// Problem Statement
// You are given N coders (1 ≤ N ≤ 300000), conveniently numbered from 1 to N. Each of these coders 
// participates in both High School and Open matches. For each coder, you are also given an Open 
// rating Ai and a High School rating Hi. Coder i is said to be better than coder j if and only 
// if both of coder i's ratings are greater than or equal to coder j's corresponding ratings,
// with at least one being greater. For each coder i, determine how many coders coder i is better than.
// Input Format
// On the first line of input is a single integer N, as described above. N lines then follow. Line i+1 contains two space-separated integers, Ai and Hi.
// Output Format
//  Line i should contain the number of coders that coder i is better than.
// Sample Input 1:
// 8
// 1798 1832
// 862 700
// 1075 1089
// 1568 1557
// 2575 1984
// 1033 950
// 1656 1649
// 1014 1473
// Sample Output 1:
// 6
// 0
// 2
// 4
// 7
// 1
// 5
// 1
// Explanation
// 1st code is better than 2nd, 3rd, 4th, 5th, 6th and 7th coder.
// Hence he is better than 6 coders.


#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, pair<int, int> >& a, pair<int, pair<int, int> >&b){
    if(a.first==b.first){
        return a.second.first<b.second.first;
    }
    return a.first<b.first;
}


void update(int x, int* bit){
    for( ; x<=100000 ; x+=(x&(-x))){
        bit[x]++;
    }
}

int query(int x, int* bit){
    int count = 0;
    for(; x>0; x -= (x&(-x))){
        count += bit[x];
    }
    
    return count;
}


int main(){
    
    // write your code here
    int n;
    cin>>n;
    pair<int, pair<int, int>>* arr = new pair<int, pair<int, int>>[n+1]();
    for(int i=1; i<=n; i++){
        cin>>arr[i].first>>arr[i].second.first;
        arr[i].second.second = i;
    }
    
    sort(arr+1, arr+n+1, compare);
    int* bit = new int[100001]();
    int* ans = new int[n+1]();
    
//     for(int i=1; i<=n; i++){
//         cout<<arr[i].first<<" "<<arr[i].second<<endl;
//     }
    
    
    for(int i=1; i<=n; ){
    	
        int endIndex = i;
        
        while(endIndex<=n && arr[i].first==arr[endIndex].first && arr[i].second.first==arr[endIndex].second.first){
            endIndex++;
        }
        for(int j=i; j<endIndex; j++){
            ans[arr[j].second.second] = query(arr[j].second.first, bit); 
        }
        
        for(int j=i; j<endIndex; j++){
            update(arr[j].second.first, bit);
        }
        
        i = endIndex;
    }
    
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<endl;
    }
    
    return 0;
}
