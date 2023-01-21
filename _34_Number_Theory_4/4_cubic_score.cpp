// Cubic Square
// Send Feedback
// Varun is learning method of successive squaring so that he can calculate a^b mod m quickly. 
// To give himself practice he wrote many tuples of a, b and m and went to school thinking that he will do it after school.
// After school he found that tuples he wrote are modified by his little sister. His sister 
// converted each b into base 3. Varun wrote everything in base 10.
// Help Varun to do his exercise.
// Input Format:
// First line of input contains a number T(number of test case). Each test case contains an integer 
// a(base 10) followed by a string b (base 3) followed by integer m (base 10). All are space-separated.
// Output Format;
// Output a number for each test case a^b mod m in base 10 in new line.
// Constraints:
// 1 <= T <= 1000
// 1 <= a, m <= 10^9
// Number of digits in b will be less than 250.
// Sample Input:
// 2
// 2 10 10
// 3 21101 19
// Sample Output:
// 8
// 3
#include<bits/stdc++.h>
using namespace std;
int main(){
   
    int t;
    cin>>t;
    while(t--){
        long long  a;
        string b;
        long long m;
        cin>>a>>b>>m;
        if(b.empty()){
            cout<<1<<endl;
            continue;
        }
        long long res = 1;
        long long k = a;
        for(int i=b.length()-1; i>=0; i--){
            if(b[i]=='0'){
                
            }
            if(b[i]=='1'){
                res = (res%m * k%m )%m;
            }
            if(b[i]=='2'){
                res = (res%m * k%m * k%m )%m;
            }
            
            k = ((k * k)%m * k%m)%m;
        }
        
        cout<<res<<endl;
        
        
    }
    return 0;
}
