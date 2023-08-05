#include <iostream>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b) {
	while(b != 0) {
    		int r = a % b;
    		a = b;
    		b = r;
	}
	return a;
}

unsigned long long powerMod(unsigned long long a, unsigned long long x, unsigned long long p) {
	unsigned long long result = 1;
	a %= p;
	while(x != 0){
    		if(x & 1) result = (result * a) % p;
    		x = x >> 1;
    		a = (a * a) % p;
	}
	return result;
}

bool primalityCheck(unsigned long long n) {
	if(n == 0 or n == 1) return false;
	srand(time(NULL));
	unsigned long long k = 100;
	for(unsigned long long i = 0; i < k; ++i) {
    		unsigned long long random = 2 + rand() % (n-3);
    		if(gcd(random, n) != 1) return false;
    		if(powerMod(random, n-1, n) != 1) return false;
	}
	return true;
}

double probabilityOfLiars(unsigned long long compositeNumber) {
	int liars=0;
	for(int i = 2; i <= compositeNumber-2; ++i) {
    		if(powerMod(i, compositeNumber-1, compositeNumber) == 1) ++liars;
	}
	return double(liars) / (compositeNumber - 3);
}

int main() {
	unsigned long long n = 1997;
	primalityCheck(n) ? cout << "prime" << endl : cout << "composite" << endl;
    	return 0;
}
