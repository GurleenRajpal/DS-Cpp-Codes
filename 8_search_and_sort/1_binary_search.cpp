int binarySearch(int *input, int n, int val)
{
    //Write your code here
    int start = 0;
    int end = n-1;
    int mid;
    while(start<=end){
        mid = (start+end)/2;
        if(input[mid]==val) return mid;
        
        if(input[mid]>val){
            end = mid - 1;
        }
        
        if(input[mid]<val){
            start = mid + 1;
        }
    }
    return -1;
}
