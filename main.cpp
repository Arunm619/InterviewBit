#include <iostream>
#include <vector>
#include <set>

using namespace std;


vector<int> getNext(vector<int> prev) {
    vector<int> next;
    int size = prev.size() + 1;
    next.resize(size);
    next.push_back(1);
    for (int i = 0; i < prev.size() - 1; i++) {
        next.push_back(prev[i] + prev[i + 1]);
    }
    next.push_back(1);
    return next;
}

vector<vector<int> > solve(int A) {
    vector<int> firstRow{1};
    vector<vector<int>> result{firstRow};
    auto prev = firstRow;
    for (int i = 0; i < A; i++) {
        auto next = getNext(prev);
        result.push_back(next);
        prev = next;
    }

    return result;
}


int main() {

//    auto res = solve(4);
//    for (auto &i : res) {
//        for (auto &j : i) {
//            cout << j << " ";
//        }
//        cout << endl;
//    }


    for (auto &i : getNext({1})) {
        cout << i << " ";
    }


    return 0;
}