// Rectangular Area
// Send Feedback
// You are given N rectangles, which are centered in the center of the Cartesian coordinate system and their sides are parallel to the coordinate axes. Each rectangle is uniquely identified with its width (along the x-axis) and height (along the y-axis). Navdeep has coloured each rectangle in a certain colour and now wants to know the area of the coloured part of the paper. Please refer to the sample test case 1 and image used in it for better understanding.
// Sample Input 1 :
// 3 
// 8 2 (represented by white coloured rectangle)
// 4 4 (represented by blue coloured rectangle)
// 2 6 (represented by yellow coloured rectangle)
// Sample Output 1 :
// 28
// Alt Text

// In other words, he wants to know the number of unit squares that belong to at least one rectangle. This 
// can also be seen in the image. There are 28 unit squares, which come in the bounds of at least one rectangle.
// Input Format :
// The first line of input contains the integer N, that denotes the number of rectangles.
// Each of the following N lines contains even integers X and Y, dimensions (width and height, respectively) of the corresponding rectangles. 
// Output Format :
// The first and only line of output must contain the required area, as described in the task. 
// Constraints:
// 1 <= N <= 10^5
// 1 <= X,Y <= 10^5
// All values of X and Y are even
// Time Limit: 1 second 
// Sample Input 1 :
// 3 
// 8 2
// 4 4 
// 2 6 
// Sample Output 1 :
// 28
// Sample Input 2 :
// 5 
// 2 10 
// 4 4 
// 2 2 
// 8 8 
// 6 6 
// Sample Output 2 :
// 68

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    
    // write your code here
    ll n;
    cin>>n;
    
    ll a[500000] = {0};
    ll count = 0;
    ll largest = 0;
    while(n--){
        ll x, y;
        cin>>x>>y;
        
        x = x/2;
        
        if(x>largest){
            largest = x;
        }
        
        ll height = y;
        
        for(ll i=x; i>=1; i--){
        	if(a[i]<height){
                a[i] = height;
            }
            else{
                break;
            }
        }
    }
    for(ll i=1; i<=largest; i++){
       	count+=a[i];   
    }
    
    cout<<count*2<<endl;
    
    
    return 0;
}
