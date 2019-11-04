int Solution::maximumGap(const vector<int> &A) {
    if (A.size() < 2) return 0;
    vector<int> copy(A.begin(), A.end());
    sort(begin(copy), end(copy));
    int mx = INT_MIN;
    for (int i = 1; i < copy.size(); i++) {
        mx = max(mx, copy[i] - copy[i - 1]);
    }
    return mx;
}


//priority queue solution
int Solution::maximumGap(const vector<int> &A) {
    if(A.size()<2) return 0;
    priority_queue<int> pq(begin(A),end(A));
    int prev = pq.top(); pq.pop();
    int mx = INT_MIN,top;
    while(!pq.empty()){
        top = pq.top();
        pq.pop();
        mx = max(mx,prev -top);
        prev = top;
    }

    return mx;
}


/**
 * Time - O(NlogN)
 * Space - O(N)

    Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

    Try to solve it in linear time/space.

    Example :

    Input : [1, 10, 5]
    Output : 5
    Return 0 if the array contains less than 2 elements.

    You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
    You may also assume that the difference will not overflow.

  */