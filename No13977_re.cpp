#include <iostream>
#include <vector>

/*
 * 각 쿼리별 수행하면서 총 시간초과가 나지 않으려면
 * O(1) per Quarry 가 되어야 한다.
 * DP를 사용하여 미리 값들을 할당을 해 놓아야 하는데
 * nCr 을 400만개를 하기엔 좀 그렇다.
 * mod 를 할당하는 방식을 해보자!
 */

using namespace std;
typedef unsigned long long ull;

const ull p = ull(1e9) + 7;
vector<ull> fac(4e6 + 1, 1); // for A
vector<ull> inv(4e6 + 1, 1); // for B^(-1)
vector<ull> ans;
int tc;
ull N, K;

ull power(int num, int jisu) {
	if (!jisu) return 1; // num^0 = 1 이므로
	if (jisu % 2)
		return (power(num, jisu - 1) * num) % p;

	ull half = power(num, jisu / 2) % p;
	return (half * half) % p;
}

void init() {
	for (int i = 2; i <= 4e6; i++) fac[i] *= (fac[i - 1] * i) % p;
	inv[4e6] = power(fac[4e6], p - 2);
	for (int i = 3999999; i >= 0; i--) {
		inv[i] = (inv[i + 1] * (i + 1)) % p;
		
	}
}

void solve(ull n, ull k) {
	ull temp = fac[n];
	temp = (temp * inv[k]) % p;
	temp = (temp * inv[n - k]) % p;

	ans.push_back(temp);
}

int main() {
	init();

	cin >> tc;
	while (tc--) {
		cin >> N >> K;
		solve(N, K);
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}

// https://justicehui.github.io/ps/2019/08/21/BOJ13977/