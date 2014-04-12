//Authors: Lucas Wiener & Mathias Lindblom

#ifndef _prime_sieve_h_
#define _prime_sieve_h_

#include <vector>
#include <math.h>
#include <algorithm>

typedef int number;

/**
 * Will calculate Erathostenes sieve by segmentation to not use more than O(sqrt(n)) memory,
 * and stores the primes found in an vector for prime lookup.
 */
class PrimeSieve {
	number n;
	std::vector<number> primes;
    
public:
	/**
	 * Calculates the primes up to n.
	 */
	PrimeSieve(number n) {
		primes = sieve(n);
	}
    
    /**
     * Returns true if q is a prime. q Needs to be <= n.
     */
	bool prime(number q) {
		auto it = std::lower_bound(primes.begin(), primes.end(), q);
		return it != primes.end() && *it == q;
	}
    
	size_t size() {
		return primes.size();
	}
    
private:
	/**
	 * Performs the segmented sieve.
	 */
	std::vector<number> sieve(number n) {
		std::vector<number> r;
        
		number max = sqrt((double)n);
        
		int segment_size = 30000;
        
		std::vector<bool> low_primes = vanilla_sieve(max);
        
		for(int i = 2; i < low_primes.size(); i++) {
			if(low_primes[i]) {
				r.push_back(i);
			}
		}
        
		std::vector<bool> sieve(segment_size, true);
        
		number limit = max;
        
		while(limit < n) {
			std::fill(sieve.begin(), sieve.end(), true);
			for(number i = 2; i < low_primes.size(); i++) {
				if(low_primes[i]) {
					number p = i;
                    
					for(number k = p - (limit % p) - 1; k < segment_size; k += p) {
						sieve[k] = false;
					}
				}
			}
            
			for(number i = 0; i < sieve.size(); i++) {
				if(i + limit > n) {
					break;
				}
                
				if(sieve[i]) {
					r.push_back(i + limit +1);
				}
			}
            
			limit += segment_size;
		}
        
		return r;
	}
    
    /**
     * Performs a naive sieve.
     */
	std::vector<bool> vanilla_sieve(number n) {
		std::vector<bool> v(n + 1, true);
        
		number p = 2;
        
		while(true) {
			for(number q = 2 * p; q <= n; q += p) {
				v[q] = false;
			}
            
			bool found = false;
			for(number i = p + 1; i <= n; i++) {
				if(v[i]) {
					p = i;
					found = true;
					break;
				}
			}
            
			if(!found) {
				break;
			}
		}
        
		return v;
	}
};

#endif