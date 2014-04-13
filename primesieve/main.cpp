//Authors: Lucas Wiener & Mathias Lindblom

#include <cstdio>
#include "primesieve.h"

int main() {
	int n, q;

	scanf("%d %d", &n, &q);

	PrimeSieve ps(n);

	printf("%zu\n", ps.size());

	for(int i = 0; i < q; i++) {
		int q;

		scanf("%d", &q);

		printf("%d\n", (ps.prime(q) ? 1 : 0));
	}

	return 0;
}