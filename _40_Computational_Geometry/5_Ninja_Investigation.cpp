//  Ninja Investigations
// Send Feedback
// A recent non violent protest in Uptown Plaza took a drastic turn as a bomb was blasted by some resurgent. 
// Ninja Investigations was hired to determine the responsible party. Using advanced satellite systems and GPS
// tracking of cell phones, the investigators determined the coordinates of every person in the plaza. Using 
// some advanced algorithms, the investigative team has also determined the approximated coordinates of the 
// bomb and the vicinity in which a person had to be if he planted the bomb. You have been given a very important 
// task - narrow down the suspect pool. To do this, you have to find out whether a given person was in the vicinity
// of the bomb. Also print the probability that they planted the bomb. The probability can be calculated using 
// the following formula:

// 100 - (distance of point to be checked with approx coordinates of bomb /  total area of the vicinity).

// Note: A person in the plaza may not be carrying a phone and their coordinates might be unknown. 
// But we can disregard such people, because the bomb was cell phone triggered, hence it would be 
// impossible for a person not carrying the phone to plant and trigger the bomb.
// Note: Get the answer of distance and area in double, then typecast it in int. Print probability in int also.
// Input Format:

// First line contains integer t, representing the number of test cases.
// For each test case
// Line 1: contains integer n, number of vertices of vicinity.
// Next n lines contain coordinates of vertices of vicinity.
// Next line contains approximate coordinates of the bomb.
// Next line contains integer q, number of coordinates to be checked.
// Next q lines contain coordinates of the people to be checked.

// Output Format:

// For each test case, print “Yes” if the person is present in the vicinity of the bomb and the probability 
// that he planted the bomb in the next line, otherwise print “No”.

// Sample Case 1:

// 1
// 3
// 1 10
// 9 1
// 10 7
// 5 6
// 2
// 8 6
// 8 8

// Sample Output 1:

// Yes
// 90
// No

#include<bits/stdc++.h>
using namespace std;
bool toChange(pair<int, int>p, pair<int, int> q, pair<int, int> r){
    int x1 = q.first - p.first;
    int y1 = q.second - p.second;
    int x2 = r.first - q.first;
    int y2 = r.second - q.second;
    int ans = x1 * y2 - x2 * y1;
    return ans<0;
}
double farea(vector<pair<int, int>>& ans){
    double fArea = 0;
    int n = ans.size();
    for(int i=1; i<n-1; i++){
        double x1 = ans[i].first - ans[0].first;
        double y1 = ans[i].second - ans[0].second;
        double x2 = ans[i+1].first - ans[0].first;
        double y2 = ans[i+1].second - ans[0].second;
        double cross = x1 * y2  - x2 * y1;
        fArea += cross;
    }
    fArea = fArea/2;
    return abs(fArea);
}
void f(pair<int, int>* arr, int n, vector<pair<int, int>>& ans){
    int p = 0, start;
    int q, r;
    start = p;
    for(int i=1; i<n; i++){
        if(arr[i].first<arr[p].first){
            p = i;
        }
    }
    start = p;

    do{
        ans.push_back(arr[p]);
        q = (p+1)%n;
        for(int i=0; i<n; i++){
            if(toChange(arr[p], arr[q], arr[i])){
                q = i;
            }
        }
        p = q;
    }while(p!=start);
}

bool inside(int x, int y, vector<pair<int, int>>& ans){
    bool result = true;
    int n = ans.size();
    for(int i=0; i<ans.size()-1; i++){
        if(toChange(ans[i], ans[i+1], make_pair(x, y) )){
            result = false;
            return result;
        }
    }

    if(toChange(ans[n-1],ans[0], make_pair(x, y) )){
        result = false;
        return result;
    }
    return result;
}

int main(){
    // write your code
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        pair<int, int>* arr = new pair<int, int>[n];
        for(int i=0; i<n; i++){
            cin>>arr[i].first>>arr[i].second;
        }
        vector<pair<int, int>> convexHull;
        f(arr, n, convexHull);
        //we have convexHull
        double area = farea(convexHull);
        // cout<<convexHull.size()<<endl;
        // for(int i=0; i<convexHull.size(); i++){
        //     cout<<convexHull[i].first<< " "<<convexHull[i].second<<endl;
        // }
        // cout<<"Area:"<<area<<endl;
        int bombX, bombY;
        cin>>bombX>>bombY;

        int q;
        cin>>q;
        while(q--){
            int x, y;
            cin>>x>>y;
            if(!inside(x, y, convexHull)){
                cout<<"No"<<endl;
            }
            else{
                //calculate probability
                cout<<"Yes"<<endl;
                double distance = sqrt((x - bombX)*(x - bombX) + (y - bombY)*(y - bombY));
                // cout<<distance<<endl;
                distance = (int) distance;
                area = (int) area;
                // distance /= area;
                // cout<<distance<<endl;
                // distance*=100;
                // cout<<"Area"<<area<<endl;
                int prob = 100*((distance*1.0)/(area*1.0));
                cout<<100-prob<<endl;
            }
        }
    }
    return 0;
}
