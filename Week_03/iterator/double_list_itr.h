class iterator {
  private:
	  Node *current;

  public:
	// Public constructor for iterator.
	iterator() {
		current = nullptr;
	}

	iterator(Node *p) {
		current = p;
	}

	const Object & operator* () {
		return current->data;
	}

	/* Post-in/decrement. */
	iterator operator++ (int) {
		iterator old = *this;
		++(*this);
		return old;
	}

	iterator operator-- (int) {
		iterator old = *this;
		--(*this);
		return old;
	}

	/* Pre-in/decrement. */
	iterator & operator++ () {
		current = current->next;
		return *this;
	}

	iterator & operator-- () {
		current = current->prev;
		return *this;
	}

	bool operator== (const iterator & rhs) {
		return current == rhs.current;
	}

	bool operator!= (const iterator & rhs) {
		return !(*this == rhs);
	}

	friend class List<Object>;
};
