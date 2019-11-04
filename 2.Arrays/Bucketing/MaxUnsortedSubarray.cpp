vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    int start = 0, end = n-1;

    //finding start
    int i;
    for(i = 0; i < n - 1 ; i++){
        if(A[i] > A[i+1]){
            start = i;
            break;
        }
    }

    //the entire array is sorted.
    if(i == n-1){
        return {-1};
    }

    //finding end.
    for(i = n-1; i>0 ; i--){
        if(A[i] < A[i-1]){
            end = i;
            break;
        }
    }

    //now we have start and end of candidates.
    //find min and max in the subarray btwn start to end.

    int mini = INT_MAX, maxi = INT_MIN;

    for(i=start; i<=end; i++){
        mini = min(mini,A[i]);
        maxi = max(maxi,A[i]);
    }

    //we have max and min from candidate subarray.



    //going from left to start, to find the position where min will fit in.
    for(i = 0; i < start; i++ ){
        if(A[i]>mini){
            start = i;
            break;
        }
    }

    //going from end to end of array to find the position where max will fit in.
    for(i = n-1; i>=end+1;i--){
        if(A[i] < maxi){
            end = i;
            break;
        }
    }

    return {start,end};
}

/*
    1.find left_i
    2.find right_i

    0 1 2 3 4
    1 3 2 4 5
    left_i = 1
    right_i = i < i+1 i+1 ans - 2

    left = 1
    right = 2

    find min & max in left to righ = min - 2 and max - 3

    find min in 0 to 1 position where you keep min is 1
    find max in 2 to 4 position where you keep max is


*/


/**
 * Time - O(N)
 * Space - O(1)
 *

    You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
    Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
    If A is already sorted, output -1.

    Example :

    Input 1:

    A = [1, 3, 2, 4, 5]

    Return: [1, 2]

    Input 2:

    A = [1, 2, 3, 4, 5]

    Return: [-1]
    In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.
  */