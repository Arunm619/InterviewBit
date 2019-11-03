class Solution {
public:
    vector<int> plusOne(vector<int> &A) {
        std::reverse(begin(A), end(A));
        int sum = 0, carry = 1;
        int i = 0;
        while (i < A.size() and carry) {

            sum = A[i] + carry;
            carry = sum / 10;
            sum = sum % 10;
            A[i] = sum;
            i++;
        }

        if (carry == 1) {
            A.push_back(1);
        }

        while (A.back() == 0) {
            A.pop_back();
        }

        std::reverse(begin(A), end(A));

        return A;
    }
};

/**
 * Time - O(N)
 * Space - O(1)

Given a non-negative number represented as an array of digits,
add 1 to the number ( increment the number represented by the digits ).
The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

 */