

vector<int> generateNextRow(vector<int> prev) {
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

vector<int> generate(int row) {
    if (row == 0) {
        return {1};
    } else {
        return generateNextRow(generate(row - 1));
    }
}




/**
 * Time - O(N)
 * Time - O(N)


 Given an index k, return the kth row of the Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Input : k = 3

Return : [1,3,3,1]
 NOTE : k is 0 based. k = 0, corresponds to the row [1].
Note:Could you optimize your algorithm to use only O(k) extra space?
 */