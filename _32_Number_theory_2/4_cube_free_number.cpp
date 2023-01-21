// Find The Cube Free Number
// Send Feedback
// A cube free number is a number who’s none of the divisor is a cube number (A cube number 
// is a cube of a integer like 8 (2 * 2 * 2) , 27 (3 * 3 * 3) ). So cube free numbers are 
// 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18 etc (we will consider 1 as cube free). 
// 8, 16, 24, 27, 32 etc are not cube free number. So the position of 1 among the cube free numbers is 1, 
// position of 2 is 2, 3 is 3 and position of 10 is 9. Given a positive number you have to say if its a cube 
// free number and if yes then tell its position among cube free numbers.
// Note: we will consider 1 as the 1st cube free number
// Input Format:
// First line of the test case will be the number of test case T 
// Each test case contain an integer N
// Output Format:
// For each test case print the position of N in cube free numbers and if its not a cube free number print "Not Cube Free" in a newline.
// Constraints:
// 1 <= T <= 10^5
// 1 <= N <= 10^6
// Sample Input:
// 10
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// Sample Output:
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// Not Cube Free
// 8
// 9


#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int z = 1e6+1;
    vector<bool>v (z, true);
    
    v[0] = false;
    v[1] = false;
    
    for(int i=2; i*i<z; i++){
        if(v[i]==false){
            continue;
        }
        for(int j=i*i; j<z; j+=i){
            if(j%i==0){
                v[j] = false;
            }
        }
    }
    
    vector<bool>x (z, false);
    for(int i=2; i*i*i<z; i++){
        if(v[i]==false){
            continue;
        }
        for(int j = i*i*i; j<z; j+=i*i*i){
            x[j] = true;
        }
    }
    v.clear();
    
    vector<int>y (z, 0);
    y[1] = 1;
    int count = 2;
    for(int i=2; i<z; i++){
        if(x[i] == false){
            y[i] = count;
            count++;
        }
    }
    
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        if(x[a]==false){
            cout<<y[a]<<endl;
        }
        else{
            cout<<"Not Cube Free"<<endl;
        }
    }
    
    return 0;
}
