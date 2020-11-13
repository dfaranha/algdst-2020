#ifndef _QUADRATIC_PROBING_H_
#define _QUADRATIC_PROBING_H_

#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

int nextPrime(int n);
bool isPrime(int n);

template <typename HashedObj>
class HashTable {
  public:
	HashTable(int size = 101):array(nextPrime(size)) {
		makeEmpty();
	}

	bool contains(const HashedObj& x) const;
	void makeEmpty();
	bool insert(const HashedObj& x);
	bool remove(const HashedObj& x);

	enum EntryType { ACTIVE, EMPTY, DELETED };

  private:
	struct HashEntry {
		HashedObj element;
		EntryType info;

		HashEntry(const HashedObj& e = HashedObj {}, EntryType i = EMPTY)
			: element {e}, info{i}{}
	};

	vector<HashEntry> array;
	int currentSize;

	bool isActive(int currentPos) const;
	int findPos(const HashedObj& x) const;
	void rehash();
	size_t myhash(const HashedObj& x) const;
};

#include "hash_table_probing.tpp"

#endif
