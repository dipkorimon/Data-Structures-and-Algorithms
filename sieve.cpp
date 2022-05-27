#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 10000;
bitset<mx> bs;
vector<int> primes;
void sieve(long long upper_bound) {
    bs.set();
    bs[0] = bs[1] = 0;
    primes.push_back(2);
    for(long long i = 3; i <= upper_bound + 1; i += 2) {
        if(bs[i]) {
            for(long long j = i * i; j <= upper_bound + 1; j += 2*i)
                bs[j] = 0;
            primes.push_back((int) i);
        }
    }
}
void isPrime (int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 != 0 && bs[n]) return true;
}

int main() {
    sieve(1000); 
    return 0;
}
