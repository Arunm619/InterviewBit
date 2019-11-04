#include <iostream>
#include <vector>
#include <set>

using namespace std;

void print(vector<vector<int>> &a) {
    cout << endl;
    for (auto &i : a) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void setZeroes(vector<vector<int> > &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    int hasfirstrowZero = 0, hasfirstcolZero = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                if (i == 0) hasfirstrowZero = 1;
                if (j == 0) hasfirstcolZero = 1;

                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {

            if (matrix[i][0] == 0 or matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (hasfirstcolZero) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }


    if (hasfirstrowZero) {
        for (int i = 0; i < m; i++) {
            matrix[0][i] = 0;
        }
    }
}

int main() {


    vector<vector<int>> mat{
            {0, 1},
            {1, 1}
    };
    print(mat);
    setZeroes(mat);

    print(mat);

    return 0;
}