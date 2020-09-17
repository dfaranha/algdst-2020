template <typename Object>
void Vector<Object>::resize( int newSize ) {
	if( newSize > theCapacity )
		reserve( newSize * 2 );
	theSize = newSize;
}

template <typename Object>
void Vector<Object>::reserve(int newCapacity) {
	int i;

	if(newCapacity < theSize)
		return;

	Object *newArray = new Object[newCapacity];
	for(i = 0; i < theSize; ++i) {
		newArray[i] = objects[i];
	}

	theCapacity = newCapacity;
	delete [] objects;
	objects = newArray;
}

template <typename Object>
void Vector<Object>::push_back(const Object &x) {
	if( theSize == theCapacity )
		reserve(2 * theCapacity + 1);
	objects[theSize++] = x;
}

template <typename Object>
void Vector<Object>::pop_back() {
	if(empty()) {
		throw underflow_error{};
	}
	theSize--;
}

template <typename Object>
const Object &Vector<Object>::back() {
	if(empty()) {
		throw underflow_error{};
	}
	return objects[theSize - 1];
}
