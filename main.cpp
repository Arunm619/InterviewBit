#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;


/*
 3.Merge Intervals
 4.Merge Overlapping Intervals
 5.N/3 Repeat Numbers.
 6.Simple Queries.
 */



struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
    //sorts based on first value
    static bool compare(Interval a, Interval b) {
        return a.start < b.start;
    }

    static vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() <= 1) return intervals;
        vector<Interval> result;
        sort(begin(intervals), end(intervals), compare);
        auto prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            auto cur = intervals[i];

            if (prev.end >= cur.start) {
                prev.end = max(prev.end, cur.end);
            } else {
                result.push_back(prev);
                prev = cur;
            }
        }
        result.push_back(prev);
        return result;
    }
};


bool compare(Interval &A, Interval &B) {
    return A.start < B.start;
}

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    intervals.push_back(newInterval);

    if (intervals.size() <= 1) return intervals;
    vector<Interval> result;
    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
        auto current = intervals[i];
        if (result.back().end < current.start) {
            //overlaps.
            result.emplace_back(current);
        } else {
            result.back().end = std::max(result.back().end, current.end);
        }
    }
    return result;
}


int main() {
    vector<Interval> A{{1, 3},
                       {3, 4}};
    A = insert(A, {40, 48});
    for (auto &i : A) {
        cout << i.start << " -> " << i.end << " \n";
    }
    return 0;
}