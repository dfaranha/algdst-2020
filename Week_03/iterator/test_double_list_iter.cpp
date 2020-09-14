using namespace std;

#include <iostream>
#include "double_list.h"

int main(int argc, char *argv[]) {
	List<int> *list = new List<int>();
	List<int>::iterator iter;

	list->push_back(10);
	list->push_back(5);
	list->push_back(3);
	list->push_back(7);

	cout << "List size:      " << list->size() << endl;
	for (iter = list->begin(); iter != list->end(); iter++) {
		cout << "Next element:   " << *iter << endl;
	}

	delete list;
}
