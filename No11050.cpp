#include <iostream>
#include <vector>
// 이항계수

using namespace std;

vector<int> fact(11, 1);

int main() {
	for (int i = 1; i <= 10; i++) {
		fact[i] = i * fact[i - 1];
	}

	int n, r;

	cin >> n >> r;

	cout << (fact[n] / (fact[n - r] * fact[r]));
}