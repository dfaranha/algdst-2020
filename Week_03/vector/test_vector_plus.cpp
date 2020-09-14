#include <iostream>
#include "vector_plus.h"

using namespace std;

int main(void) {
	int i;
	/* We initialize with default capacity, resize later. */
	Vector<int> v;
	Vector<int>::iterator iter;

	/* Reserve space for 25 elements */
	v.reserve(20);
	cout << "Capacity: " << v.capacity() << " elements" << endl;
	for (i = 0; i < 20; ++i) {
		v.push_back(i);
	}
	for(iter = v.begin(); iter != v.end(); iter++) {
	    cout << *iter << " ";
	}
	cout << endl;

	Vector<int> s = v.slice(1, v.size() - 1);

	/* Now let us process the slice through iterator */
	for(iter = s.begin(); iter != s.end(); iter++) {
	    cout << *iter << " ";
	}
	cout << endl;

   return 0;
}
