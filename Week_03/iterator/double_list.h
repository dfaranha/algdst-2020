#ifndef _LIST_H_
#define _LIST_H_

template <typename Object> class ListIter;

template <typename Object>
class List {
  private:
    struct Node {
        Object  data;
        Node   *next;
		Node   *prev;
    };
	int   theSize;
	Node *head;
    Node *tail;

  public:
	List() {
		theSize = 0;
		head = new Node; tail = new Node;
		head->next = tail;
		tail->prev = head;
		head->prev = tail->next = nullptr;
	}

	~List() { clear(); delete head; delete tail; }

	int size() { return theSize; }
	bool empty() { return (size() == 0); }

	void clear();
	void push_front(const Object& x);
	void push_back(const Object& x);
	Object pop_front();
    Object pop_back();

	/* We define the iterator in another file. */
	#include "double_list_itr.h"

	iterator begin() {
		return iterator(head->next);
	}

	iterator end() {
		return iterator(tail);
	}

	iterator insert(iterator itr, const Object& x) {
		Node *p = itr.current;
		Node *q = new Node();
		q->data = x;
		q->prev = p->prev;
		q->next = p;
		p->prev = p->prev->next = q;
		theSize++;
		return iterator(q);
	}

	iterator erase(iterator itr) {
		Node *p = itr.current;
		iterator retVal{ p->next };
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		theSize--;

		return retVal;
	}
};

#include "double_list.tpp"

#endif
