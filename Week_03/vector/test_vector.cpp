#include <iostream>
#include "vector.h"

using namespace std;

int main(void) {
	int i;
	/* We initialize with default capacity, resize later. */
	Vector<int> v;
	Vector<int>::iterator iter;

	cout << "Capacity: " << v.capacity() << " elements" << endl;
	v.push_back(5);
	v.push_back(10);
	v.push_back(2);

	cout << "Capacity: " << v.capacity() << " elements" << endl;
	/* Reserve space for 25 elements */
	v.reserve(20);
	for (i = 0; i < 20; ++i) {
		v.push_back(i);
	}
	cout << "Capacity: " << v.capacity() << " elements" << endl;

	/* Now let us process the vector through iterator */
	for(iter = v.begin(); iter != v.end(); iter++) {
	    cout << *iter << " ";
	}
	cout << endl;

	for(iter = v.begin(); iter != v.end(); iter++) {
		*iter = *iter + 1;
	    cout << *iter << " ";
	}
	cout << endl;

   return 0;
}
