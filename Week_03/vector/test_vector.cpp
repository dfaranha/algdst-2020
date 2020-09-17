#include <iostream>
#include "vector_class.h"

using namespace std;

int main(void) {
	int i;
	/* We initialize with default capacity, resize later. */
	Vector<int> v;
	Vector<int>::iterator itr;

	cout << "Capacity: " << v.capacity() << " elements" << endl;
	v.push_back(5);
	v.push_back(10);
	v.push_back(2);

	cout << "Capacity: " << v.capacity() << " elements" << endl;
	/* Reserve space for 20 elements */
	v.reserve(20);
	for (i = 0; i < 20; ++i) {
		v.push_back(i);
	}
	cout << "Capacity: " << v.capacity() << " elements" << endl;

	/* Now let us process the vector through itrator */
	for(itr = v.begin(); itr != v.end(); itr++) {
	    cout << *itr << " ";
	}
	cout << endl;

	for(itr = v.begin(); itr != v.end(); itr++) {
		*itr = *itr + 1;
	    cout << *itr << " ";
	}
	cout << endl;

   return 0;
}
