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

template <typename Object>
Vector<Object> Vector<Object>::slice(int x, int y) {
    // The start and end iterators
    iterator start = begin() + x;
    iterator end = begin() + y + 1;
	iterator iter;

    // Store elements in the sliced vector
    Vector<Object> result;
	for (iter = start; iter != end; iter++) {
		result.push_back(*iter);
	}

    // Return the final sliced vector
    return result;
}

template <typename Object>
Object& Vector<Object>::at(int pos) {
	if (pos < 0 || pos >= size()) {
		throw out_of_range("Invalid position.");
	}
	return objects[pos];
}
