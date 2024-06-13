#include <vector>
#include <iostream>
using namespace std;

class SegmentTree2D {
    vector<vector<int>> tree;
    int rows, cols;

public:
    SegmentTree2D(int r, int c) : rows(r), cols(c) {
        tree.resize(2 * rows, vector<int>(2 * cols, 0));
    }

    void build(vector<vector<int>>& matrix) {
        // Initialize leaves of the segment tree
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                tree[i + rows][j + cols] = matrix[i][j];

        // Build the segment tree row-wise
        for (int i = rows; i < 2 * rows; ++i)
            for (int j = cols - 1; j > 0; --j)
                tree[i][j] = tree[i][2 * j] + tree[i][2 * j + 1];

        // Build the segment tree column-wise
        for (int i = rows - 1; i > 0; --i)
            for (int j = 0; j < 2 * cols; ++j)
                tree[i][j] = tree[2 * i][j] + tree[2 * i + 1][j];
    }

    void update(int row, int col, int value) {
        // Update the value at (row, col)
        int r = row + rows, c = col + cols;
        tree[r][c] = value;

        // Update the row segment tree
        for (int j = c; j > 1; j /= 2)
            tree[r][j / 2] = tree[r][j] + tree[r][j ^ 1];

        // Update the column segment tree
        for (int i = r; i > 1; i /= 2) {
            int j = c;
            while (j >= 1) {
                tree[i / 2][j] = tree[i][j] + tree[i ^ 1][j];
                j /= 2;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        row1 += rows; col1 += cols;
        row2 += rows; col2 += cols;

        for (int i = row1; i <= row2; ++i) {
            int left = col1, right = col2;
            while (left <= right) {
                if (left % 2 == 1) sum += tree[i][left++];
                if (right % 2 == 0) sum += tree[i][right--];
                left /= 2; right /= 2;
            }
        }

        return sum;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    SegmentTree2D st(3, 3);
    st.build(matrix);

    cout << "Sum of region (0, 0) to (2, 2): " << st.sumRegion(0, 0, 2, 2) << endl;

    st.update(1, 1, 10);
    cout << "Sum of region (0, 0) to (2, 2) after update: " << st.sumRegion(0, 0, 2, 2) << endl;

    return 0;
}
