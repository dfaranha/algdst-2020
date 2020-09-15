#include <iostream>
#include "vector_plus.h"

using namespace std;

int main(void) {
	int i;

	try {
		Vector<float> *f = new Vector<float>(-1);
	} catch (exception& e) {
		cout << "Allocation failed, reason: " << e.what() << endl;
	}

	/* We initialize with default capacity, resize later. */
	Vector<int> v;
	Vector<int>::iterator itr;
	Vector<int>::const_iterator citr;

	/* Reserve space for 25 elements */
	v.reserve(20);
	cout << "Capacity: " << v.capacity() << " elements" << endl;
	for (i = 0; i < 20; ++i) {
		v.push_back(i);
	}
	for(itr = v.begin(); itr != v.end(); itr++) {
	    cout << *itr << " ";
	}
	cout << endl;

	Vector<int> s = v.slice(1, v.size() - 1);

	/* Now let us process the slice through iterator */
	for(citr = s.begin(); citr != s.end(); citr++) {
	    cout << *citr << " ";
	}
	cout << endl;

   return 0;
}
