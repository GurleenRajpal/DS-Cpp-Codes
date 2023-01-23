//  Area Of Convex Polygon
// Send Feedback
// A convex polygon is a set of n vertices that are joined by n edges, such that no two edges 
// intersect and all angles are less than 180 degrees. We can represent a polygon by listing 
// all the vertices, starting at one vertex and following the edges until that vertex is reached 
// again. Thus, element 0 in the array represents the first vertex. The first vertex is connected 
// to the second vertex (element 1), the second vertex is connected to the third vertex (element 2)
// and so on. The last element represents the last vertex, which is connected to the first vertex.
// Given the vertices of a polygon, return its exact area.
// Note: Get the integer part of the area. (It can be long). So get your answer in double, and typecast it into long.
// Input Format:

// First line of input will contain T(number of test cases), each test case follows.
// Line 1: Integer N denoting the number of points.
// Next N lines will denote the N cordinates (x,y) in a anticlockwise order.

// Constraints:

// 1 <= T <= 10^5
// 1 <= N <= 50
// 1 <= X <= Y <= 10^5
// The given polygon is guranted to be convex.

// Output Format:

// For each test case, print the area of polygon in new line.

// Sample Input 1:

// 1
// 4
// 1 5
// 2 2
// 9 2
// 7 5

// Sample Output 1:

// 19

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n, x, y;
        cin>>n;
        pair<int, int>* arr = new pair<int, int>[n];
        for(int i=0; i<n; i++){
            int a, b;
            cin>>a>>b;
            arr[i].first = a;
            arr[i].second = b;
        }
        if(n==0 || n==1){
            cout<<0<<endl;
            continue;
        }
        int a1 = arr[0].first;
        int a2 = arr[0].second;
        int sum = 0;
        for(int i=1; i<n-1; i++){
            pair<int, int> b = arr[i];
            pair<int, int> c = arr[i+1];
            int b1 = b.first;
            int b2 = b.second;
            int c1 = c.first;
            int c2 = c.second;

            int abx = b1 - a1;
            int aby = b2 - a2;

            int acx = c1 - a1;
            int acy = c2 - a2;

            int val = abx*acy - acx*aby;

            sum += val;
        }
        cout<<sum/2<<endl;

    }
    return 0;
}
