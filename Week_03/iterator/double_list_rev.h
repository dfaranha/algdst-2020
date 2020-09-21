class reverse_iterator {
  private:
	  Node *current;

  public:
	// Public constructor for reverse_iterator.
	reverse_iterator() {
		current = nullptr;
	}

	reverse_iterator(Node *p) {
		current = p;
	}

	const Object& operator* () {
		return current->data;
	}

	/* Post-in/decrement. */
	reverse_iterator operator++ (int) {
		reverse_iterator old = *this;
		--(*this);
		return old;
	}

	reverse_iterator operator-- (int) {
		reverse_iterator old = *this;
		++(*this);
		return old;
	}

	/* Pre-in/decrement. */
	reverse_iterator & operator++ () {
		current = current->prev;
		return *this;
	}

	reverse_iterator & operator-- () {
		current = current->next;
		return *this;
	}

	bool operator== (const reverse_iterator & rhs) {
		return current == rhs.current;
	}

	bool operator!= (const reverse_iterator & rhs) {
		return !(*this == rhs);
	}

	friend class List<Object>;
};
