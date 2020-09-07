int sum(int n) {
	int i, partialSum = 0;

	for (i = 1; i <= n; i++) {
		partialSum = partialSum + (i * i * i);
	}
	return partialSum;
}
