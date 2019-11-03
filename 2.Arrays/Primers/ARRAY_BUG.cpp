#include <iostream>
#include <vector>

using namespace std;

vector<int> rotateArray(vector<int> &A, int B) {
    vector<int> ret;
    ret.reserve(A.size());

    for (size_t i = 0; i < A.size(); i++) {
        ret.push_back(A[(i + B) % A.size()]);
    }
    return ret;
}


int main() {
    vector<int> V{2, 3, 4, 5, 6, 1};
    auto result = rotateArray(V, 1);
    for (auto &i : result) cout << i << " ";
}