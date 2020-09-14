using namespace std;

#include <iostream>
#include "double_list.h"

int main(int argc, char *argv[]) {
	List<int> *list = new List<int>();
	List<int>::iterator itr;

	list->push_back(10);
	list->push_back(5);
	list->push_back(3);
	list->push_back(7);

	cout << "List size:      " << list->size() << endl;
	for (itr = list->begin(); itr != list->end(); itr++) {
		cout << "Next element:   " << *itr << endl;
	}

	/* We need to overload operator + to perform arithmetic. */
	itr = list->begin();
	itr++;
	itr = list->insert(itr, 20);
	itr++;
	itr = list->erase(itr);
	cout << "List size:      " << list->size() << endl;
	for (itr = list->begin(); itr != list->end(); itr++) {
		cout << "Next element:   " << *itr << endl;
	}

	delete list;
}
