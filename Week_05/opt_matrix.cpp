using namespace std;

#include <climits>
#include "matrix_class.h"

/**
* Compute optimal ordering of matrix multiplication.
* c[0] is the number of rows in matrix 1, next entries contain
* the number of columns for each of the n matrices.
* The minimum number of multiplications is returned.
* Actual ordering is computed via another procedure using lastChange.
* For simplicity, m and lastChange are indexed starting at 1, instead of 0.
*
* Note: Entries below main diagonals of m and lastChange
* are meaningless and uninitialized.
*/
int optMatrix(const vector<int>&c, Matrix<int>&m,
		Matrix<int>&lastChange) {
	int n = c.size() - 1;

	for (int left = 1; left <= n; ++left)
		m[left][left] = 0;

	for (int k = 1; k < n; ++k) {
		// k is right - left
		for (int left = 1; left <= n - k; ++left) {
			// For each position
			int right = left + k;
			m[left][right] = INT_MAX;
			for (int i = left; i < right; ++i) {
				int thisCost = m[left][i] + m[i + 1][right]
						+ c[left - 1] * c[i] * c[right];
				if (thisCost < m[left][right]) { // Update min
					m[left][right] = thisCost;
					lastChange[left][right] = i;
				}
			}
		}
	}

	return m[1][n];
}

int main(int argc, char *argv[]) {
	vector<int> input = {50, 10, 40, 30, 5};
	Matrix<int> m(5, 5), change(5, 5);

	cout << optMatrix(input, m, change) << endl;
}
