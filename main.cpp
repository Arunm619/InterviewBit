#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

//1.find permutation
vector<int> findPermutation(string &secret) {
    vector<int> combination;
    stack<int> st;
    int walker = 1;
    for (char &c : secret) {
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


/*
 1.Find Permutation
 2.Next Permutation
 3.Merge Intervals
 4.Merge Overlapping Intervals
 5.N/3 Repeat Numbers.
 6.Simple Queries.
 */

void permute(string &s, string &newString, vector<string> &vec) {
    if (s.empty()) {
        vec.push_back(newString);
    } else
        for (int idx = 0; idx < s.size(); idx++) {
            newString.push_back(s[idx]);
            s.erase(idx, 1);
            permute(s, newString, vec);
            s.insert(idx, 1, newString.back());
            newString.pop_back();
        }
}

void generateAllPermutations(string s) {
    vector<string> result;
    string chosen;
    permute(s, chosen, result);
    for (auto &i : result) {
        cout << i << " \n";
    }
}

vector<int> nextPermutationVC(vector<int> A) {
    int n = A.size();
    int k = 0;
    for (k = n - 2; k >= 0; k--) {
        if (A[k] < A[k + 1]) {
            break;
        }
    }
    if (k == 0) {
        reverse(begin(A), end(A));
        return A;
    } else {
        int l = 0;
        for (l = n - 1; l >= 0; l--) {
            if (A[l] > A[k]) {
                break;
            }
        }
        swap(A[l], A[k]);
        reverse(begin(A) + k + 1, end(A));
    }
    return A;
}



vector<int> nextPermutationSTL(vector<int> A) {
    if (next_permutation(begin(A), end(A))) {
        cout << "There is next permutaion!";
    } else {
        cout << "Reversing!";

        cout<<"Before:\n";
        for (auto &i : A) cout << i << ' ';
        cout<< "\nAfter\n";
        reverse(begin(A), end(A));
        for (auto &i : A) cout << i << ' ';
    }


    return A;
}


int main() {

    auto res = nextPermutationSTL({3, 2, 1});


   // for (auto &i : res) cout << i << ' ';
    return 0;
}