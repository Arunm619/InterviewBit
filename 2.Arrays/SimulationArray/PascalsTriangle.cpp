
vector<int> getNext(vector<int> &prev) {
    vector<int> next;
    int size = prev.size() + 1;
    next.reserve(size);
    next.push_back(1);
    for (int i = 0; i < prev.size() - 1; i++) {
        next.push_back(prev[i] + prev[i + 1]);
    }
    next.push_back(1);
    return next;
}

vector <vector<int>> Solution::solve(int A) {
    if (A == 0) return {};
    vector<int> firstRow{1};
    vector <vector<int>> result{firstRow};
    auto prev = firstRow;
    for (int i = 1; i < A; i++) {
        auto next = getNext(prev);
        result.push_back(next);
        prev = next;
    }

    return result;
}


/**
 * Time - O(N)
 * Space - O(1)
 *

 Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

        Return

[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]

 */