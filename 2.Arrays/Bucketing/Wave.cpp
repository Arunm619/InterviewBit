vector<int> Solution::wave(vector<int> &A) {
    sort(begin(A), end(A));
    for (int i = 0; i < A.size() - 1; i += 2) {
        swap(A[i], A[i + 1]);
    }
    return A;
}

/**
 * Time - O(NlogN)
 * Space - O(1)
 *

Given an array of integers, sort the array into a wave like array and return it,
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

Example

Given [1, 2, 3, 4]

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]
 NOTE : If there are multiple answers possible, return the one thats lexicographically smallest.
So, in example case, you will return [2, 1, 4, 3]

 Since it is asked to find lexicographically smaller sequence, we cannot do better than nlogn otherwise we can do in linear time.


vector<int> Solution::wave(vector<int> &A) {
    bool flag = true;
    for(int i= 0; i < A.size()-1; i++)
    {
        if(flag){
            if(A[i]<A[i+1])
                swap(A[i],A[i+1]);
        }
        else{
            if(A[i]>A[i+1])
                swap(A[i],A[i+1]);
        }
        flag = !flag;
    }
    return A;
}

 */