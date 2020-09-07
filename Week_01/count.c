#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i, j, k, N, count = 0;

	N = atoi(argv[1]);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				count++;
			}
		}
	}

	printf("Count = %d\n", count);
}
