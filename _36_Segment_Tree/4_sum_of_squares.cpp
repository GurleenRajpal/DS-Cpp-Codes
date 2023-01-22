// Sum Of Squares
// Send Feedback
// Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to 
// compute sums over a range in O(lg(n)), and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
// The sum of squares over a range with range updates of 2 types:
// 1) increment in a range
// 2) set all numbers the same in a range.
// There will be T test cases in the input file. First line of the input contains two positive integers, N and Q.
// The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:
// 2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).

// 1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and 1 <= x <= 1,000).

// 0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and 1 <= x <= 1,000).
// Input Format:
// First line of input will contain T(number of test case), each test case follows as.
// Line 1: contain two space-separated integers denoting the value of N and Q respectively
// Line 2: contain N space-separated integers denoting th value of array elements
// Next Q line contain the space separated value for queries as defined as above.
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 10000
// 1 <= arr[i] <= 1000
// 1 <= Q <= 10000
// Output Format:
// For each test case, print the answer in new line for query of type 2
// Sample Input 1:
// 2
// 4 5
// 1 2 3 4
// 2 1 4
// 0 3 4 1
// 2 1 4
// 1 3 4 1
// 2 1 4
// 1 1
// 1
// 2 1 1
// Sample Output 1:
// 30
// 7
// 13
// 1

#include<bits/stdc++.h>
using namespace std;

class treeVal{
	public:
    	int square;
    	int sum;
};

class lazyVal{
    public:
    	int set;
    	int inc;
};

class newLazy{
  	public:
    	int value=0;
    	int type=2;
};

void buildTree(treeVal* tree, int* arr, int start, int end, int treeNode){
    if(start==end){
        tree[treeNode].square = arr[start]*arr[start];
        tree[treeNode].sum = arr[start];
        return;
    }
    
    int mid = (start+end)/2;
    buildTree(tree, arr, start, mid, 2*treeNode);
    buildTree(tree, arr, mid+1, end, 2*treeNode+1);
    
    tree[treeNode].square = tree[2*treeNode].square+tree[2*treeNode+1].square;
    tree[treeNode].sum = tree[2*treeNode].sum + tree[2*treeNode+1].sum;
    
}

treeVal newquery(treeVal* tree,newLazy* lazy, int start, int end, int treeNode, int left, int right){
    if(start>end){
        treeVal ans;
        ans.square = 0;
        ans.sum = 0;
        return ans;
    }
    
    if(lazy[treeNode].type==1 && lazy[treeNode].value!=0){//inc
        int range = end-start+1;
        tree[treeNode].square += 2*lazy[treeNode].value*tree[treeNode].sum + lazy[treeNode].value*lazy[treeNode].value*range;
        tree[treeNode].sum += lazy[treeNode].value*range;
        
        if(start!=end){
            lazy[2*treeNode].value += lazy[treeNode].value;
            lazy[2*treeNode+1].value += lazy[treeNode].value;
            lazy[2*treeNode].type = 1;
            lazy[2*treeNode+1].type = 1;
        }
        lazy[treeNode].value = 0;
        lazy[treeNode].type = 2;
    }
    
    if(lazy[treeNode].type==0 && lazy[treeNode].value!=0){
        int range = end-start+1;
        tree[treeNode].square = lazy[treeNode].value*lazy[treeNode].value*range;
        tree[treeNode].sum = lazy[treeNode].value*range;
        
        if(start!=end){
            lazy[2*treeNode].value = lazy[treeNode].value;
            lazy[2*treeNode+1].value = lazy[treeNode].value;
            lazy[2*treeNode].type = 0;
            lazy[2*treeNode+1].type = 0;
        }
        lazy[treeNode].value = 0;
        lazy[treeNode].type = 2;
    }
    
    if(right<start || left>end){
        treeVal ans;
        ans.square = 0;
        ans.sum = 0;
        return ans;
    }
    

    if(start>=left && end<=right){
        return tree[treeNode];
    }
    
    int mid = (start+end)/2;
    treeVal ans1 = newquery(tree, lazy, start, mid, 2*treeNode, left, right);
    treeVal ans2 = newquery(tree, lazy, mid+1, end, 2*treeNode+1, left, right);
    
    treeVal ans;
    ans.square = ans1.square+ans2.square;
    ans.sum = ans1.sum+ans2.sum;
    
    return ans;
    
}
void update(treeVal* tree, newLazy* lazy, int start, int end, int treeNode, int left, int right, int x, int type){
    
    if(start>end){
        return;
    }
    
    if(lazy[treeNode].type==1 && lazy[treeNode].value!=0){//inc
        int range = end-start+1;
        tree[treeNode].square += 2*lazy[treeNode].value*tree[treeNode].sum + lazy[treeNode].value*lazy[treeNode].value*range;
        tree[treeNode].sum += lazy[treeNode].value*range;
        
        if(start!=end){
            lazy[2*treeNode].value += lazy[treeNode].value;
            lazy[2*treeNode+1].value += lazy[treeNode].value;
            lazy[2*treeNode].type = 1;
            lazy[2*treeNode+1].type = 1;
        }
        lazy[treeNode].value = 0;
        lazy[treeNode].type = 2;
    }
    
    if(lazy[treeNode].type==0 && lazy[treeNode].value!=0){//set
        int range = end-start+1;
        tree[treeNode].square = lazy[treeNode].value*lazy[treeNode].value*range;
        tree[treeNode].sum = lazy[treeNode].value*range;
        
        if(start!=end){
            lazy[2*treeNode].value = lazy[treeNode].value;
            lazy[2*treeNode+1].value = lazy[treeNode].value;
            lazy[2*treeNode].type = 0;
            lazy[2*treeNode+1].type = 0;
        }
        lazy[treeNode].value = 0;
        lazy[treeNode].type = 2;
    }
    
    if(type==0){//set all value to x
        int range = end-start+1;
        if(start>right || end<left){
            return;
        }

        if(start>=left && end<=right){
            tree[treeNode].square = range*x*x;
            tree[treeNode].sum = x*range;
            if(start!=end){
                lazy[2*treeNode].value = x;
                lazy[2*treeNode+1].value =x;
                lazy[2*treeNode].type = 0;
                lazy[2*treeNode+1].type = 0;
            }
            return;
        }

        int mid = (start+end)/2;

        update(tree, lazy, start, mid, 2*treeNode, left, right, x, type);
        update(tree, lazy, mid+1, end, 2*treeNode+1, left, right, x, type);

        tree[treeNode].square = tree[2*treeNode].square+tree[2*treeNode+1].square;
        tree[treeNode].sum = tree[2*treeNode].sum+tree[2*treeNode+1].sum;
        return;
    }
    if(type==1){//inc all value by x
        int range = end-start+1;
        if(start>right || end<left){
            return;
        }
        
        if(start>=left && end<=right){
            tree[treeNode].square += range*x*x + 2*x*tree[treeNode].sum;
            tree[treeNode].sum += x*range;
            if(start!=end){
                lazy[2*treeNode].value += x;
                lazy[2*treeNode+1].value +=x;
                lazy[2*treeNode].type = 1;
                lazy[2*treeNode+1].type = 1;
            }
            return;
        }

        int mid = (start+end)/2;

        update(tree, lazy, start, mid, 2*treeNode, left, right, x, type);
        update(tree, lazy, mid+1, end, 2*treeNode+1, left, right, x, type);

        tree[treeNode].square = tree[2*treeNode].square+tree[2*treeNode+1].square;
        tree[treeNode].sum = tree[2*treeNode].sum+tree[2*treeNode+1].sum;
        return;
    }
    
    
}


int main(){
    
    // write your code he
    int t;
    cin>>t;
    while(t--){
        
        int n, q;
        cin>>n>>q;
        
        int* arr = new int[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        
        treeVal* tree = new treeVal[4*n]();
        lazyVal* lazy = new lazyVal[4*n]();
        newLazy* lazyTree = new newLazy[4*n]();
        
        buildTree(tree, arr, 0, n-1, 1);
        // cout<<tree[4].sum<<" "<<tree[4].square<<endl;
        while(q--){
            int option;
            cin>>option;
            if(option==2){
                int a, b;
                cin>>a>>b;
                cout<<newquery(tree, lazyTree, 0, n-1, 1, a-1, b-1).square<<endl;
            }
            if(option==1){
                int a,b,c;
                cin>>a>>b>>c;
                // lazy_inc(tree, lazy, 0, n-1, 1, a-1,b-1, c);
                update(tree, lazyTree, 0, n-1, 1, a-1, b-1, c, 1);
            }
            if(option==0){
                int a,b,c;
                cin>>a>>b>>c;
                // lazy_set(tree, lazy, 0, n-1, 1, a-1,b-1, c);
                update(tree, lazyTree, 0, n-1, 1, a-1, b-1, c, 0);
            }    
        }
    }
    return 0;
}
