#include <iostream>
#include <vector>
#include <set>

using namespace std;

int cmp(const string &a, const string &b) {
    string ab = a + b;
    string ba = b + a;
    return ab > ba;
}

string largestNumber(vector<int> A) {
    vector<string> S;
    S.reserve(A.size());
    for (auto &i : A) S.push_back(to_string(i));
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
    return res;
}


int main() {

//    auto res = solve(4);
//    for (auto &i : res) {
//        for (auto &j : i) {
//            cout << j << " ";
//        }
//        cout << endl;
//    }

    cout << largestNumber({1, 2, 3, 4});


    return 0;
}