// Winning Strategy
// Send Feedback
// The college team, along with their coach, is going to the sports fest to play a football match. 
//   There are n players in the team, numbered from 1 to n.
// Someone gives a paper to the coach. The paper elaborates on the positions and strategies of the 
// opponent team. Based on it, the coach creates a winning strategy. In that strategy, he decides and gives a particular position to every player.
// After this, the coach starts swapping two players at a time to make them stand according to new positions decided on paper.
// He swaps players by applying following rules:
// 1. Any player can swap with the player standing next to him. 
// 2. One player can swap with at most two other players.
// Given that initially all the players are standing linearly, numbered from 1 to n, you have to tell 
// whether it is possible for the coach to create new positions by swapping within the constraints defined in the task.
// Input Format
// The first line of input will contain an integer, that denotes the value of the number of test cases. 
// Let us denote the number of test cases by the symbol T.
// Each of the following T test cases consists of two lines. The first line of each test case contains an 
// integer n, that denotes the number of players in the team. The following line contains n space separated integers, 
// denoting the specific position of players in winning strategy.  
// Output Format
// For each test case, if it is possible to create winning strategy positions, then print "YES" (without quotes) and 
// in the next line, print the minimum numbers of swaps required to form the winning strategy order, otherwise print "NO"(without quotes) in a new line.
// Constraints
// 1 <= T <= 50
// 1 =< N <= 10^5 
// 1 <= A[i] <= n
// Time Limit: 1 second
// Sample Input 1:
// 1
// 5
// 2 1 5 3 4
// Sample Output 1:
// YES
// 3
// Explanation
// In this case, we can achieve winning strategy positions in 3 swaps. Initial state of positions: 1 2 3 4 5
// Three moves required to form winning strategy positions:
// 1 2 3 4 5 -> 1 2 3 5 4 -> 1 2 5 3 4 -> 2 1 5 3 4
// Sample Input 2:
// 1
// 5
// 2 5 1 3 4
// Sample Output 2:
// NO   
// Explanation:
// In the second case, there is no way to form the specific winning strategy positions by 
// swapping within the constraints mentioned in the task.

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        int arr[n];
        int b[n];
        for(int i=0;i<n; i++){
            cin>>arr[i];
            b[i] = arr[i];
            b[i]--;
            b[i] = abs(b[i] - i);
        }
        bool ans = false;
        for(int i=0; i<n; i++){
            if(b[i]>2){
                ans = true;
                break;
            }
        }
        int swaps = 0;
        if(ans){
            cout<<"NO"<<endl;
        }
        else{
            // for(int i=0; i<n-3;){
            //     int x = arr[i];
            //     int y = arr[i+1];
            //     int z = arr[i+2];
            //     if(arr[i]==i+1){
            //         i=i+1;
            //         continue;
            //     }
            //     if(x>y && x>z){
            //         if(y>z){//x>y>z
            //             swaps+=3;
            //         }
            //         else{//x>z>y
            //             swaps+=2;
            //         }
            //     }
            //     if(y>x && y>z){
            //         if(x>z){//y>x>z
            //             swaps+=1;
            //         }
            //         else{//y>z>x
            //             swaps+=1;
            //         }
            //     }
            //     if(z>x && z>y){
            //         if(x>y){//z>x>y
            //             swaps+=1;
            //         }
            //         else{//z>y>x
            //             swaps+=0;
            //         }
            //     }
            //     sort(arr+i, arr+i+3);
            // 	i=i+3;
            // }
            
            for(int i=0; i<n-2; ){
                if(arr[i]==i+1){
                    i=i+1;
                    continue;
                }
                else if(arr[i]==i+2){
                   if(arr[i+1]==i+1){
                       swap(arr[i], arr[i+1]);
                       swaps+=1;
                       i+=1;
                   }
                   else if(arr[i+1]==i+3 && arr[i+2]==i+1){
                       swap(arr[i+1], arr[i+2]);
                       swap(arr[i+1], arr[i]);
                       swaps+=2;
                       i+=2;
                   }
                   else if(arr[i+1]>0 && arr[i+2]==i+1){
                       swap(arr[i+1], arr[i+2]);
                       swap(arr[i+1], arr[i]);
                       swaps+=2;
                       i=i+1;
                   }
                    
                   else{
                       swap(arr[i], arr[i+1]);
                       swaps+=1;
                       i+=1;
                   }
                    
                }
                else if(arr[i]==i+3){
                    if(arr[i+1]==i+1 && arr[i+2]==i+2){
                        swap(arr[i], arr[i+1]);
                        swap(arr[i+1], arr[i+2]);
                        swaps+=2;
                        i+=2;
                    }
                    else if(arr[i+1]==i+2 && arr[i+2]==i+1){
                        swap(arr[i+1], arr[i+2]);
                        swap(arr[i], arr[i+1]);
                        swap(arr[i+1], arr[i+2]); 
                        swaps+=3;
                        i+=3;
                    }
                    else{
                       swap(arr[i], arr[i+1]);
                       swaps+=1;
                        i+=1;
                    }
                }
            	
            }
            if(arr[n-2]==n){
                swap(arr[n-1], arr[n-2]);
                swaps+=1;
            }
            
            cout<<"YES"<<endl;
            cout<<swaps<<endl;
        }
        
        
    }
    return 0;
}
