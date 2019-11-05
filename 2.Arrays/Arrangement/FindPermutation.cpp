/// https://leetcode.com/articles/find-permutation/
vector<int> findPerm(const string secret, int B) {
    vector<int> combination;
    stack<int> st;
    int walker = 1;
    for (const char &c : secret) {
        if (c == 'D') {
            st.push(walker);
        } else {
            //if it is 'I'
            st.push(walker);
            while (!st.empty()) {
                combination.push_back(st.top());
                st.pop();
            }
        }
        walker++;
    }

    st.push(walker);
    while (!st.empty()) {
        combination.push_back(st.top());
        st.pop();
    }

    return combination;
}


/**
 * Time - O(N)
 * Space - O(N) Stack
 *

    Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

    D means the next number is smaller, while I means the next number is greater.

    Notes

            Length of given string s will always equal to n - 1
    Your solution should run in linear time and space.
    Example :

    Input 1:

    n = 3

    s = ID

    Return: [1, 3, 2]

 */