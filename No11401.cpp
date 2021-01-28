#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;

const ull p = ull(1e9) + 7;
ull N, K;

ull power(int num, int jisu) {
	if (!jisu) return 1; // num^0 = 1 ÀÌ¹Ç·Î
	if (jisu % 2)
		return (power(num, jisu - 1) * num) % p;
	
	ull half = power(num, jisu / 2) % p;
	return (half * half) % p;
}

int main() {
	cin >> N >> K;

	ull A = 1, B = 1;
	// A = n!, B = (n-k)!k!

	for (ull i = 1; i <= N; i++) {
		A *= i;
		A %= p;

		if (i <= K) {
			B *= i;
			B %= p;
		}
		if (i <= N - K) {
			B *= i;
			B %= p;
		}
	}

	ull ans = (A * (power(B, p - 2))) % p;

	cout << ans;
}