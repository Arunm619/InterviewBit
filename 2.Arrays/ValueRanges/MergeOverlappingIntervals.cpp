/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval a, Interval b){
    return a.start<b.start;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    if(A.size()<1) return A;
    sort(begin(A),end(A),cmp);
    vector<Interval> result;
    auto prev = A[0];

    for(int i = 1; i < A.size(); i++){
        auto current = A[i];

        if(prev.end >= current.start){
            prev.end = std::max(prev.end,current.end);
        }
        else{
            result.push_back(prev);
            prev = current;
        }
    }

    result.push_back(prev);
    return result;
}


/**
 * Time - O(NlogN)
 * Space - O(1)
 *

    Given a collection of intervals, merge all overlapping intervals.

    For example:

    Given [1,3],[2,6],[8,10],[15,18],

    return [1,6],[8,10],[15,18].

    Make sure the returned intervals are sorted.
  */