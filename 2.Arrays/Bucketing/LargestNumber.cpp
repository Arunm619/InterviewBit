
string Solution::largestNumber(const vector<int> &A) {
    vector <string> S;
    S.reserve(A.size());
    for (auto &i : A) {
        S.push_back(to_string(i));
    }
    sort(begin(S), end(S), [](const string &a, const string &b) {
             string ab = a + b;
             string ba = b + a;
             return ab > ba;
         }
    );
    string res;
    for (auto &i : S) {
        res += i;
    }
    reverse(begin(res), end(res));
    while (res.back() == '0' and res.size() > 1) res.pop_back();
    reverse(begin(res), end(res));

    return res;
}

/**
 * Time - O(NlogN)
 * Space - O(1)


    Given a list of non negative integers, arrange them such that they form the largest number.

    For example:

    Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

    Note: The result may be very large, so you need to return a string instead of an integer.
 */