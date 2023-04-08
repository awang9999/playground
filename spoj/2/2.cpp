// Input:

// The input begins with the number t of test cases in a single line (t<=10).
// In each of the next t lines there are two numbers m and n
// (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

// Output:
// For every test case print all prime numbers p such that m <= p <= n,
// one number per line, test cases separated by an empty line.

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function finds all primes from 2 to n and
// stores the result in the vector, primes
void simpleSieve(int limit, int low, vector<int> &primes) {
  vector<bool> mark(limit+1, true);

  for (int p = 2; p < limit+1; p++){
    if (mark[p]) {
      for(int i = p*p; i < limit + 1; i += p){
        mark[i] = false;
      }
    }
  }

  for(int p = 2; p < limit+1; p++){
    if(mark[p]){
      primes.push_back(p);
      if(p >= low){
        cout << p << endl;
      }
    }
  }
}

// Performs the segmented sieve algorithm to print all
// primes within the range [m,n].
//
// segmentSize is the size of the local array
// m is lower bound
// n is upper bound
void segmentedSieve(int m, int n) {
  // Compute all primes less than sqrt(n) using a
  // simple sieve.
  int lim = floor(sqrt(n))+1;
  vector<int> primes;
  primes.reserve(lim);
  simpleSieve(lim, m, primes);

  // compute range of the initial segment
  int low = lim;  
  int high = 2*lim;

  if (m > lim) {
    low = m;
    high = m + lim;
  }

  
  // while segments in the range [m,n] are not processed,
  // continue processing segments.
  while(low <= n) {
    // If the high value exceeds n, cap it at n.
    if(high > n){
      high = n;
    }

    // Create a mark vector to mark primes in the
    // range of the current segment. If i - low is prime,
    // mark[i] is true
    vector<bool> mark(lim + 1, true);

    // Use the primes found in simpleSieve to find the
    // primes in the current range.
    for (int i = 0; i < primes.size(); i++) {
      
      // Find the smallest number in [low, high] that is
      // a multiple of prime[i] (i.e. divisible by prime[i])
      int lowLim = floor(low / primes[i]) * primes[i];
      if (lowLim < low) {
        lowLim += primes[i];
      }

      // Mark multiples of prime[i] in the range [low, high]
      // the quantity (j-low) corresponds to j in the range
      // [low, high]. That is, each number [low, high] is
      // mapped to [0, high - low].
      for(int j = lowLim; j < high+1; j += primes[i]){
        mark[j - low] = false;
      }
      
    }

    // Print remaining primes in the segment
    for (int i = low; i < high+1; i++) {
      if (mark[i - low]) {
        cout << i << endl;
      }
    }
    
    low = high + 1;
    high += lim;
  }
}

int main() {
  int t;
  int m, n;

  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> m;
    cin >> n;
    // Strategy: Segmented sieve.

    segmentedSieve(m, n);
    
    // print space between outputs for each test case except for
    // the last one.
    if (i < t-1){
      cout << "\n"; 
    }
  }
  
  return 0;
}
