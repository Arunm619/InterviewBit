
#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(const vector<vector<int>> &A) {
    vector<int> result;
    int row = A.size();
    int col = A[0].size();
    int dir = 0;
    int top = 0, left = 0, right = col - 1, bottom = row - 1;
    while (top <= bottom and left <= right) {
        switch (dir) {
            case 0: {
                //go from left to right on top
                for (int i = left; i <= right; i++) {
                    result.push_back(A[top][i]);
                }
                top++;
                break;
            }
            case 1: {
                //go from top to bottom on right
                for (int i = top; i <= bottom; i++) {
                    result.push_back(A[i][right]);
                }
                right--;
                break;
            }
            case 2: {
                //go from right to left on bottom
                for (int i = right; i >= left; i--) {
                    result.push_back(A[bottom][i]);
                }
                bottom--;
                break;
            }
            case 3: {
                //go from bottom to top on left
                for (int i = bottom; i >= top; i--) {
                    result.push_back(A[i][left]);
                }
                left++;
                break;
            }
        }
        dir = (dir + 1) % 4;
    }
    return result;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > matrix(n, vector<int>(m, 0));
    for (auto &i : matrix) for (auto &j : i) cin >> j;
    for (auto &i : spiralOrder(matrix)) {
        cout << i << " ";
    }

}

