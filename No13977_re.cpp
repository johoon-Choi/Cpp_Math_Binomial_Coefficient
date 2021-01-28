#include <iostream>
#include <vector>

/*
 * �� ������ �����ϸ鼭 �� �ð��ʰ��� ���� ��������
 * O(1) per Quarry �� �Ǿ�� �Ѵ�.
 * DP�� ����Ͽ� �̸� ������ �Ҵ��� �� ���ƾ� �ϴµ�
 * nCr �� 400������ �ϱ⿣ �� �׷���.
 * mod �� �Ҵ��ϴ� ����� �غ���!
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
	if (!jisu) return 1; // num^0 = 1 �̹Ƿ�
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