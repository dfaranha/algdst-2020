#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

#include <iostream>
#include <iomanip>
#include <vector>

template <typename Object>
class Matrix {
	private:
		vector<vector<Object>> array;

	public:
		Matrix() {};

		Matrix(int rows, int cols) : array(rows) {
			for(auto& r : array) {
				r.resize(cols);
			}
		}

		Matrix(vector<vector<Object>> v) : array{v} { }

		const vector<Object>& operator[](int row) const {
			if (row < 0 || row >= array.size())
				throw out_of_range("Invalid row.");
			return array[row];
		}

		vector<Object>& operator[](int row) {
			if (row < 0 || row >= array.size())
				throw out_of_range("Invalid row.");
			return array[row];
		}

		int numrows() const { return array.size( ); }

		int numcols() const {
			if (numrows() > 0) {
				return array[0].size();
			}
			return 0;
		}

		void add(Matrix& mat);
};

#include "matrix_class.tpp"

#endif
