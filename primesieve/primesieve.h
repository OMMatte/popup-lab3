#ifndef _prime_sieve_h_
#define _prime_sieve_h_

#include <set>
#include <vector>
#include <assert.h>

typedef int number;

class PrimeSieve {
	number n;
	std::set<number> primes;

public:
	PrimeSieve(number n) {
		primes = sieve(n);
	}

	bool prime(number q) {
		return primes.count(q) == 1;
	}

	size_t size() {
		return primes.size();
	}

private:
	std::set<number> sieve(number n) {
		auto isOdd = [](number i) {
			return (i & 1) == 1;
		};

		auto index = [isOdd](number i) {
			if(i == 2) {
				return 0;
			}

			return i / 2;
		};

		std::vector<number> v;


		auto print = [&v]() {
			for(int i = 0; i < v.size(); i++) {
				printf("%d ", v[i]);
			}
			printf("\n");
		};

		v.push_back(2);

		for(number i = 3; i <= n; i += 2) {
			v.push_back(i);
		}

		number p = 3;

		while(true) {
			for(number q = 3 * p; q <= n; q += 2 * p) {
				if(!isOdd(q)) {
					continue;
				}

				v[index(q)] = 0;
			}

			bool found = false;
			for(number i = p + 2; i <= n; i += 2) {
				if(!isOdd(i)) {
					continue;
				}

				if(v[index(i)] != 0) {
					p = i;
					found = true;
					break;
				}
			}

			if(!found) {
				break;
			}
		}

		std::set<number> r;

		for(int i = 0; i < v.size(); i++) {
			if(v[i] != 0) {
				r.insert(v[i]);
			}
		}

		// print();

		return r;
	}
};

#endif