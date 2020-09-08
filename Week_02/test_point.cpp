using namespace std;

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "point.h"

int main(int argc, char *argv[]) {
	int i, j, cnt = 0;

	assert(argc == 3);
	srandom(time(0));

	int N = atoi(argv[1]);
	float d = atof(argv[2]);

	Point *array = new Point[N];

	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			if (array[i].distance(array[j]) < d) {
				cnt++;
			}
		}
	}
	cout << cnt << " pairs within distance " << d << endl;
	delete [] array;
}
