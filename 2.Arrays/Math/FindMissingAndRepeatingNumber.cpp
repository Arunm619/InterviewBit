
vector<int> repeatedNumber(const vector<int> &arr) {
    map<int, int> m;
    int repeating = -1, missing = -1;
    for (auto &i : arr) {
        m[i]++;
        if (m[i] == 2) {
            repeating = i;
        }
    }
    int n = arr.size();

    for (int i = 1; i <= n; i++) {
        if (m.count(i) == 0) {
            missing = i;
            break;
        }
    }

    return {repeating, missing};
}


/**
 * Time - O(N)
 * Space - O(N)
 *

    You are given a read only array of n integers from 1 to n.

    Each integer appears exactly once except A which appears twice and B which is missing.

    Return A and B.

    Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

    Note that in your output A should precede B.

    Example:

    Input:[3 1 2 5 3]

    Output:[3, 4]

    A = 3, B = 4
 */